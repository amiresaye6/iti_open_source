#!/usr/bin/bash

echo "Enter username to inspect:"
read nameInput

userInfo=`grep "^${nameInput}:" /etc/passwd`

if [ -z "$userInfo" ]; then
    echo "Error: User '$nameInput' not found in /etc/passwd."
    exit 1
fi

homeDir=$(echo "$userInfo" | cut -d: -f6)

tempdir="/tmp/${nameInput}_home_copy"

echo "--- Home Directory List for $nameInput ($homeDir) ---"
ls -lha "$homeDir"

echo "--- Copying Files ---"

mkdir -p "$tempdir" 2>/dev/null

if [ $? -eq 0 ]; then
    cp -R "$homeDir"/{.*,*} "$tempdir" 2>/dev/null &
    echo "Copied files from $homeDir to $tempdir."
else
    echo "Copy failed."
fi

echo "ps for user $nameInput"
ps -u "$nameInput"
