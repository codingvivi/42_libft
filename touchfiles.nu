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
     'asdf'
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
    )
    create_missing_files $fn_table.ft_file
    # add_protos_to_files

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

    print $"File creation done! Created ($num_files_created) files in total.\nHow touching..."
}
