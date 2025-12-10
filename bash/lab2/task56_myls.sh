#!/bin/bash

# 5. Create a script called myls where:
# a. It lists the current directory, if it is called without arguments.
# b. Otherwise, it lists the given directory
# 6. Enhance the above script to support the following options individually:
# a. –l: list in long format
# b. –a: list all entries including the hiding files.
# c. –d: if an argument is a directory, list only its name
# d. –i: print inode number
# e. –R: recursively list subdirectories

opts=""
dest=""

if [ "$#" -ge 1 ]; then
    if [ "$1" = "-l" ]; then
        opts="$opts -l"
    elif [ "$1" = "-a" ]; then
        opts="$opts -a"
    elif [ "$1" = "-h" ]; then
        opts="$opts -h"
    else
        dest="$1"
    fi
fi

if [ "$#" -eq 2 ] && [ -z "$dest" ]; then
    dest="$2"
fi

if [ -z "$dest" ]; then
    if [ -z "$opts" ]; then
        ls
    else
        ls $opts
    fi
else
    if [ -z "$opts" ]; then
        ls "$dest"
    else
        ls $opts "$dest"
    fi
fi
