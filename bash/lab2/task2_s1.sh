#!/bin/bash


# 2. Create a script called s1 that calls another script s2 where:
# a. In s1 there is a variable called x, it's value 5
# b. Try to print the value of x in s2 by two different ways.

x=5

echo "=====script1======"

echo "first method" # pass x as argument, access it using $1
./task2_s2.sh "$x"

echo "second method" # run the script in the curren shell, sees the x varable directly , $x
. ./task2_s2.sh

