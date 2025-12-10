#!/bin/bash

# 2. Enhanced the previous script, by checking the type of string entered by a user:
# a. Upper Cases.
# b. Lower Cases.
# c. Numbers.
# d. Mix.
# e. Nothing.


read -p "Enter a string: " input_string

if [[ -z "$input_string" ]]; then
    echo "Nothing."
    exit 0
fi

if [[ "$input_string" =~ ^[A-Z]+$ ]]; then
    echo "Upper Cases."
    exit 0
fi

if [[ "$input_string" =~ ^[a-z]+$ ]]; then
    echo "Lower Cases."
    exit 0
fi

if [[ "$input_string" =~ ^[0-9]+$ ]]; then
    echo "Numbers."
    exit 0
fi

if [[ "$input_string" =~ [A-Z] ]] && [[ "$input_string" =~ [a-z] ]]; then
    echo "Mix."
    exit 0
fi

if [[ "$input_string" =~ [A-Za-z0-9]+ ]]; then
    echo "Mix."
    exit 0
fi

echo "Mix."
