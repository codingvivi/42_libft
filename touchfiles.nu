def main [] {

    let libc_fns = [
     'isalpha',
     'isdigit',
     'isalnum',
     'isascii',
     'isprint',
     'strlen',
     'memset',
     'bzero',
     'memcpy',
     'memmove',
     'strrchr',
     'strncmp',
     'strlcpy',
     'strlcat',
     'memchr',
     'memcmp',
     'toupper',
     'tolower',
     'strnstr',
     'strchr',
     'atoi',
     # 'asdf'
    ]

    let ft_names = ($libc_fns | str replace -r '^' 'ft_')
    let ft_files =  ($ft_names | str replace -r '$' '.c')

    let ref_files =  ($libc_fns | str replace -r '$' '.c')
    let ref_file_paths = (get_ref_paths $ref_files reference/musl/src)

    let fn_table = (
        $libc_fns
        | wrap 'fn'
        | merge ($ref_file_paths | wrap 'ref_path')
        | merge ($ft_names | wrap 'ft_name')
        | merge ($ft_files | wrap 'ft_file')
        | make_protos 
    )

    print $fn_table
    create_missing_files $fn_table.ft_file
    write_srcs_to_make $fn_table.ft_file
    # write_protos_to_files $fn_table


}


def get_ref_paths [fn_names: list, ref_dir: path] {
    let all_ref_files = (ls -a reference/musl/**/* | get name)

    $fn_names
    | each {|fn_to_find|
        try {
            $all_ref_files
            | where ($it | path basename  ) =~ $fn_to_find
            | first 
        } catch {
            ''
        }
    }

}

def make_protos [] {
    each {|row|
        $row
        | insert ref_protos (
            if ($row.ref_path | is-empty) {
                null
            } else {
                try {
                    open $row.ref_path
                    | lines 
                    | where $it =~ $row.fn
                    | where $it =~ '\('
                    | where not ($it | str starts-with '#')  
                    | where not ($it | str starts-with '//') 
                    | where not ($it | str contains '/*')    
                    | first
                    | str replace -r '^' 'ft_'
                } catch {
                    null
                }
            }
        )
    }
}


def create_missing_files [file_list: list] {
    
   print $'($file_list | length) files in total'

    let files_to_create = ($file_list | where not ($it | path exists))

    print $'($files_to_create| length) files missing'
    print ''

    let num_files_created = (
        $files_to_create
        | each {|curr_path|
            touch $curr_path
            print $'created ($curr_path)'
            $curr_path
        }
        | length
    )

    print $"File creation done! Created ($num_files_created) files in total."
    if ($num_files_created > 0) {
        print 'How touching 🥹'
    } else {
        print 'Not very touching 🥀'
    }
    print ''
    
}

def write_srcs_to_make [files: list] {
    
    let src_string = (
        $files
        | str replace -r '^' (char tab)
        | str join " \\ \n" 
    )
    let src_declare =  'SRCS = '

    let makefile_contents = open 'Makefile'
    if ($makefile_contents | str contains $src_declare) {
        print 'File already has sources. skipping...'
    } else {
        (
            $makefile_contents
            | lines
            | insert 1 $src_declare
            | insert 2 $src_string
            | str join (char newline)
            #| printf $in
        )
        | save -f Makefile
        print 'Added SRCS variable with value!'

    }
}

    

def write_protos_to_files [fn_table: table] {

    $fn_table
    | where {|row| $row.protos | is-not-emtpy }
    | each {|row|

        let file_contains_proto = (
            open $row.ft_files
            | lines
            | any {|line|
                ($line | str replace -ar '\s+' ' ' | str trim) 
                | like ($row.protos | str replace -ar '\s+' ' ' | str trim)
            }
        )

        if not $file_contains_proto {
            let str = $'($row.ref_protos)\n{\n}'
            print $'appending ($str) to file:($row.ft_file)'
            # $row.ft_files | save --append $row.ft_files

        }
    }
    | length | print $'Added to ($in) new files'
}

