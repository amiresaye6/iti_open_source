#!/bin/bash

# question 4 lab 4 get the suer name, and full name that starts with g
cut -d : -f 1,5 /etc/passwd | grep ^g

# question 5 lab 4 save the last question output sorted by full name in a file
cut -d : -f 1,5  /etc/passwd | grep ^g | sort -t : -k 2 >> gnames

# question 6 second lab 4 sort the output of ls on / recursivly, save the output and error in different files and send to teh backgroudn
ls -R / 2>errors.txt | sort > files.txt &

# lab5
# 1/ compress file by compress, gzip, zip, and decompress again, state the difference
compress bigFile.txt # depricated, can not run it on my machien
gzip bigFile.txt # compresses files only >> reduced from 11M to 2M
ls -lh
gunzip bigFile.txt.gz # return it to the original size
ls -lh
zip botato.zip  bigFile.txt	# compresses files and directories together >> compress from 11M to 2M as it uses the same algoright as gzip
ls -lh
unzIp bigFile.txt.zip
ls -lh

# 2/ command to display compressed file content
zcat bigfile.txt.gz

# 3/ backup /etc using tar utility
tar -cf etcBackup.tar /etc

# 4/ starting from home, fins the fiels modified in the last 2 dayes
find ~ -type f -mtime -2 2> /dev/null

# 5/ starting from /etc find files owned by root user
find /etc/ -user root 2> /dev/null

# 6/ find all directoris in my home direcotyer
find ~ -type d

# 7/ fidnn all fiels with the name .profile in the entire system
find / -type f -name ".profile" 2> /dev/null

# 8/ identify file types of /etc/passwd, /dev/pts/0, /etc, /dev/sda
file /etc/passwd
file /dev/pts/0
file /etc
file /dev/sda

# 9/ list the inode  number of /, /etc, /etc/hosts
ls -id1 / /etc/ /etc/hosts

# 10/ copy/etc/passwd, then chant ethe copy, run diff, cmp before and after
cp /etc/passwd ~/passwdCopy
diff /etc/passwd ~/passwdCopy # nothing happens
cmp /etc/passwd ~/passwdCopy # nothing happens

# changed the content of passwdCopy using vim here

diff /etc/passwd ~/passwdCopy
cmp /etc/passwd ~/passwdCopy

# both commands showd that hte file has changed and showed waht exactly changed

# 11/ create sympolic link of /etc/passwd in /boot

sudo ln -s /etc/passwd /boot/passwd_symlink

# 12/ careate hadlink of it in the same path
sudo ln /etc/passwd /boot/passwd_hardlink # will not work as had link can not be done between to differnt files systems "partitions"
