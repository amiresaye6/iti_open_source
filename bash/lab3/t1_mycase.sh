#!/bin/bash

# 1. Write a script called mycase, using the case utility to checks the type of character
# entered by a user:
# a. Upper Case.
# b. Lower Case.
# c. Number.
# d. Nothing.


echo "type check :__:"
read -r char

case "$char" in
	"")
		echo "Nothing" ;;
	[A-Z])
		echo "Upper Case" ;;
	[a-z])
		echo "Lower Case" ;;
	[1-9])
		echo "Number" ;;
	*) echo "unknown" ;;
esac
