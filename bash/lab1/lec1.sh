#!/bin/bash
#=========split=========
# -l >> lines per file
# --numeric-suffixes=1 >> start count from 1 ont 0
# -a >> so the number is 1,2,3 not 01,02, or 001, 002 ...
# the last option is the file name to use in the output
split -l 10 --numeric-suffixes=1 -a 1 /etc/passwd file;
wc -l file[1-4] # list the line counts in files from file1 to file4

#=========sed=============
# -n >> output the passing conditoin only, by default it prints any line
# -i >> overrides with the result. like save the change.
sed -n '2p' file1 # print line 2 in file1
sed -n '/root/p' file1 # print any line have the value root in it
sed -n '/root/,5p' file2 # print from the line contain root to the fifth line
sed -n '2,/^root/p' file2 # print from line 2 to teh the line starts with root
sed '3d' file2 # by default print any line, but optino d deletes line3
sed '$d' file2 # delete the last line in file
sed '1,3d' file # delete from line 1 to 3
sed '3,$d' file2 # delete from line 3 to the end, print firs and second lines
sed '/root/d' file2 #print any line, but the lines with root in it, deleted.
sed 's/nologin/login/g' file2 # replace any nologin word with login , /g to change any occurances
sed -n 's/nologin/login/gp' file2 # do the same but print the lines changed
sed - e '2d' -e 's/botato/botatochips/g' file3 # -e allow running multible commands at the same command

#=========awk==========
# -F >> field seperator to stop at for each field, $0 >> whoal record, $1,.. record number
awk -F: '{print $1,"||", $5}' /etc/passwd
awk -F: '{print $1"||"$5}' /etc/passwd # with no extra spaces
awk -F: '{print NR$0}' /etc/passwd # will print the record number and the record

awk -F: 'BEGIN{ print "LogName\t\tFullName" } { print $1"\t\t" $5 }' /etc/passwd # begin runs ones at the start
awk 'BEGIN{ print "LogName\t\tFullName"; FS=":" } { print $1"\t\t" $5 }' /etc/passwd # use ; to use multible commands a the start or the end

awk 'END{ print "LogName\t\tFullName"} { print $1"\t\t" $5 }' /etc/passwd

# if, else, ternary operation
# condition exp1? exp2 : exp3
# if () {} else if () {} else {}
# <, <=, ==, !=, >=, >, ~, !~
# ~ >> matches regular expression, !~ >> doesn't match regular exp
awk '{if ($0~"root") print $0}' /etc/passwd # print any line with root in it

# loops , it loops over fields in one recor, awk automatically loops over records.
awk -F: '{i=1; while(i<NF){print NF,$i;i++}}' /etc/passwd
awk '{for(i=1;i<NF;i++){print NF,$i}' /etc/passwd
