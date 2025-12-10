#/bin/bash

# 3. Write a script called mychmod using for utility to give execute permission to all files and
# directories in your home directory


for filename in *; do
    if [[ -f "$filename" ]]; then
        chmod +x "$filename"
    fi
done
