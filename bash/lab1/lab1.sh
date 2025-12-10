#!/bin/bash

#============== sed tasks================

# 1- Display the lines that contain the word “lp” in /etc/passwd file.

sed -n '/lp/p' /etc/passwd

# 2- Display /etc/passwd file except the third line.

sed  '3d' /etc/passwd

# 3- Display /etc/passwd file except the last line.

sed '%d' /etc/passwd

# 4- Display /etc/passwd file except the lines that contain the word “lp”.

sed '/lp/d' /etc/passwd

# 5- Substitute all the words that contain “lp” with “mylp” in /etc/passwd file.

sed 's/lp/mylp/g' /etc/passwd



#===========awk tasks================

# 1- Print full name (comment) of all users in the system.

awk -F: '{print $5}' /etc/passwd

# 2- Print login, full name (comment) and home directory of all users.( Print each line preceded by a line number)

awk -F: '{print RN"=>"$1"\t"$5"\t"$6}' /etc/passwd

# 3- Print login, uid and full name (comment) of those uid is greater than 500

awk -F: '{if($3 > 500){print $1"\t"$3"\t"$5}}' /etc/passwd


# 4- Print login, uid and full name (comment) of those uid is exactly 500

awk -F: '{if($3 == 500){print $1"\t"$3"\t"$5}}' /etc/passwd

# 5- Print line from 5 to 15 from /etc/passwd

awk '{if(NR >4 && NR < 16){print NR"==>" $0}}' /etc/passwd

# 6- Change lp to mylp

awk -F: '{if($1 == "lp") {$1 = "mylp"}} {print}' /etc/passwd

# 7- Print all information about greatest uid.

awk -F: '
{ if ($3 > max_uid) {
        max_uid = $3;
        max_line = $0;
    }
}
END {
    print max_line
}
' /etc/passwd

# 8- Get the sum of all accounts id’s.

awk -F: 'BEGIN{sum=0}{sum+=$3}END{print "sum is "sum}' /etc/passwd


#============ponus==============

# 1. Get the sum of accounts id’s that has the same group.

awk -F: '{
    sum_by_group[$4] += $3
}
END {
    for (group in sum_by_group) {
        print group, sum_by_group[group]
    }
}' /etc/passwd

# user group reprot :__:

echo "User-Group Report"
echo "--------------------------"
awk -F: '{print $4, $1}' /etc/passwd | sort -n |
awk '
    {
        current_gid = $1;
        username = $2;
        if (current_gid != last_gid) {
            print ""
            print "Group ID:", current_gid
            last_gid = current_gid;
        }
        print username
    }
'
