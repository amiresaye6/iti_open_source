#!/bin/bash

echo "3- list all the available shells in teh system"
cat /etc/shells
echo "or"
chsh -l


echo "4- list env vars in my current shell"
env

echo "5- list env vars of bash shell"
env

echo "6- commands to print env var value"
echo $HOME
echo "or"
printenv HOME

echo "7- my current shell name"

echo $SHELL
echo "or "
echo $0


echo "11- creatre alias"
alias ls='ls -l'

