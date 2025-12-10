#!/usr/bin/bash

item="$1"

echo "===============Checking type==============="

if [ -f "$item" ]; then
    echo "Is a file."
elif [ -d "$item" ]; then
    echo "Is a directory."
else
    echo "not a file or directory."
fi

echo "=================perm check=================="

if [ -r "$item" ]; then
    echo "Readable"
else
    echo "Nor Readable"
fi

if [ -w "$item" ]; then
    echo "Writable"
else
    echo "Not Writable"
fi

if [ -x "$item" ]; then
    echo "Executable"
else
    echo "Not Executable"
fi
