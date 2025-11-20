let files_to_make = [
 'isalpha',
 'isdigit',
 'isalnum',
 'isascii',
 'isprint',
 'strlen',
 'memset',
 'bzero'
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
 ]


$files_to_make | each {|filename|
 let full_file_name = ($filename | append ".c" | str join '' | str replace -r '^' 'ft_' )
 touch $full_file_name
 print $'touched ($full_file_name)'
} 

print "\nDone! How touching..."
