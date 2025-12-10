#!/bin/bash
cut -d : -f 1; >> this will slice  using the delimiter ":" and return the first result in each record
tail -4 /etc/passwd  | cut -d : -f 1,3,5 >> we can use it in piplines , we can specify the column numbers we need to return

sort /etc/passwd >> will sort the file content based on the first char in each row
sort -t : -k 1 /etc/passwd >> -t delimter, -k chose the field to sort on
sort -t : -k 3 /etc/paswd >> will sort based on strings not numbers
sort -t : -k 3 -n /etc/paswd >> with -n we specify to sort on numbers if the filed is numeric
sort -t : -k 3 -n -o botato.txt /etc/passwd >> obtion -o will output the result in a file "botato"

cut -d : -f 1,3,5 /etc/passwd | sort -t : -k 2 -n >> botato.txt >> using the two commands together

df >> return teh whoal file system disk free

ls -i botato >> will return the inode number of this file

ln -s ~/home/botato ~/home/amiralsayed >> making a sympolic link for botato file in amir directory

ln ~/home/botato ~/home/amiralsayed  >> making hard lin for botato

du . >> disk usage on the curent directory
du . -h >> human redable
du . -h -s >> with summary
du . -hs 2> /dev/null >> will redirect all the errors to null file to not be showin to th output

locate botato >> like find command, but faster, have its local database but not updated any time but find is more accurate
sudo updatedb >> will update the database with all the new stuff like the new file botato

find /etc -user 1000 2> /dev/null  >> we can search with find using the user
find /etc -name  passwd 2> /dev/null >> or with file name 
find /etc -perm 644 2> /dev/null  >> find with premessino
find /etc -perm 644 -type f  2> /dev/null >> you can specify the type too as file f, direcorty d 
find /etc -mtime 4 >> find by modification time, + >> more than, - >> les than, exact >> exact number of dayes

# tar >> archive only >> compine multible files to gether only for saving them, doesnt reduce size
# gzip, bzip2 >> compress only >> reduce the size of the data
# zip >> archive and compress at the same time >> both

tar -c -f botato.tar botato1 botato2 >> -c create archive file. -f output file "contain files and directories"
tar -tf botato.tar >> will show its content

# to un archive 
tar -xf botato.tar >> will unback the files again

#to compress
gzip botato >> fast, compress more 
#to uncompress
gunzip botato.gz >> uncompress the file

bzib2 botato >> the most powerfull compression, but slow

# to get teh size in human readable format
ls -lh  >> will show the size correctly

# to unzip
bunzip2 botato.bz2 >> will return it to original


# zip >> works with deflat algo :__:
zip botato.zip botatofile  dir2 >> will accepts files and directories

# to list what in the .zip file
unzip -l botato.zip >> will show its data only
unzip botato.zip >> will unzip and uncompress

# to make the most effeciency, make a tar file first with all the files and directories you need, then compress usin bzip2 or using the option -j

tar -jcf botato.tar file dir
