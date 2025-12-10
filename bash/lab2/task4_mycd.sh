#!/bin/bash


# 4. Create a script called mycd where:
# a. It changed directory to the user home directory, if it is called without arguments.
# b. Otherwise, it change directory to the given directory.

if [ "$#" -eq 0 ]; then
    target_dir="$HOME"
    echo "Changing directory to home: $target_dir"
else
    target_dir="$1"
    echo "Changing directory to: $target_dir"
fi

cd "$target_dir"
