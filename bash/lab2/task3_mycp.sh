#!/bin/bash

# 3. Create a script called mycp where:
# a. It copies a file to another
# b. It copies multiple files to a directory.


dest="${!#}"

if [ "$#" -eq 2 ]; then
    if [ ! -d "$dest" ]; then
        cp "$1" "$dest"
    else
        cp "$1" "$dest"
    fi
elif [ "$#" -gt 2 ]; then
    cp "$@"
fi
