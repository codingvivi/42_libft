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

    print $ref_file_paths


     let fn_table = (
    #      {
    #          fn_name: $libc_fns,
    #          ref_path: $ref_files,
    #          ft_name: $ft_names,
    #          ft_file_names: $ft_files
    #      }
    #      | transpose -r
    #      | flatten
        $libc_fns
        | wrap 'fn'
        | merge ($ref_file_paths | wrap 'ref_path')
        | merge ($ft_names | wrap 'ft_name')
        | merge ($ft_files | wrap 'ft_file')

     )


     print ($fn_table)
    
    # create_missing_files ($fn_table | get ft_file)

    # let header_contents = (open 'libft.h')
    # open "libft.h" | lines | where ($it | str contains '*')
    # let protos_not_in_header = (
        # $list_of_fns
        # | where not ($header_contents | str contains $it)
    # )
}

# def regex_replace_list [list: list<string>, pattern: string, replacement: string] {
#     $list | str replace -r ()$pattern $replacement
# }

# def add_file_suffixes [list:list, suffix: string] {
#     regex_replace_list $list '$' $suffix
# }


def get_ref_paths [fn_names: list, ref_dir: path] {
    let all_ref_files = (ls -a reference/musl/**/* | get name)

    # $all_ref_files | where ($it | path basename )
    # 
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

    # create missing files
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

# def add_protos_to_files [fn_list: list, file_list: list] {
# }

# # prepend ft_
# def prepend_ft [fn_name: string] {
#     $fn_name
# }

# # append .c
# def append_c [file_stem: string] {
#      echo $'($file_stem).c'
# }



# create files

# create missing files

# let protos_not_in_files = (
    
    # $list_of_fns
    # | where not ()
# )

# def strings_missing [needles: list, haystack] {
    # $needles
    # | where not ($haystack)
# }



# print $protos_not_in_header
# let protos_created_in_files
