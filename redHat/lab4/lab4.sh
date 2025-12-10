#!/bin/bash

echo "1- list user commands, redirect ouput to /tmp/commands.list";
compgen > /tmp/commands.list;

echo "2- coutn user commmans";
compgen | wc -l;

echo "3-  get all users names and full names of logins that starts with g";
cat /etc/passwd | grep ^g;

echo "6.1- search for .bash_profile file";
find / -name .bash_profile 2>/dev/null;


echo "7- display no of loggedin users now";
who | wc -l;

echo "8- displaye lines from 7 to 10 of /etc/passwd";
head -n 10 /etc/passwd | tail -n 3;

echo "10- sleep for 100";
sleep 100;

echo "or run in teh backgroudn by adding & at the end"
sleep 100 &;

echo "11-  to stp we can press ctrl + z"

echo "12- to resume last commadn in fg"
# get the job number using jobs commadn, and use it here
bg %1;

echo "13- jobs commad lists all the jobs in the system";
jobs;

echo "14- send sleep commadn to forground then to backgroudn again"

sleep 100 &;
fg %1;
bg %1;

echo "15- kll sleep command";
# i can kill each process by its pid or killl all by pkill and name
pkill sleep;

echo "16 display my processes only"
top -u amiralsayed;
# or ps -fu amiralsayed

echo "17- display all processes but mine";
ps -aux | grep -v "amiralsayed";


echo "18- use pgrep to get my processes only"
pgrep -lu amiralsayed;

echo "19- kill my processes only"
pkill -u amiralsayed;






