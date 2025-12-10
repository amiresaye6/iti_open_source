# 4. Write a script called mybackup using for utility to create a backup of only files in your
# home directory.



#!/bin/bash

BACKUP_FILE="backup_$(date +%Y%m%d_%H%M%S).tar.gz"

SOURCE_DIR="$HOME"

TEMP_FILE_LIST=$(mktemp)

for item in "$SOURCE_DIR"/* "$SOURCE_DIR"/.*; do
    if [[ -e "$item" ]] && [[ -f "$item" ]]; then
        echo "$item" >> "$TEMP_FILE_LIST"
    fi
done

if [[ ! -s "$TEMP_FILE_LIST" ]]; then
    echo "No files found to backup in $SOURCE_DIR."
    rm "$TEMP_FILE_LIST"
    exit 1
fi

tar -czf "$BACKUP_FILE" -T "$TEMP_FILE_LIST"

rm "$TEMP_FILE_LIST"

