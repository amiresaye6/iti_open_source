#!/bin/bash
echo "1- adding islam suer";
sudo useradd islam -c "Islam Askar";
sudo passwd islam;
echo "2- adding islam suer";
sudo useradd baduser -c "Bad User";
sudo passwd islam;

echo "users created successfully";
tail -2 /etc/passwd;

echo "3- creating new group";
sudo groupadd pgroup -g 30000;

echo "4- creating new group";
sudo groupadd badgroup;

echo "5- adding group pgroup to islam use";
sudo usermod -aG pgroup islam;

echo "6- change islam password to password";
sudo passwd islam ;

echo "7- modify islam accoutn >> expires after 30 dayes";
sudo chage -l islam;
sudo chage -M 30 islam;
sudo chage -l islam;

echo "8- lock baduser account";
sudo usermod -L baduser;

echo "9- delete bad user";
sudo userdel -r baduser ;

echo "10- delete bad group";
sudo groupdel badgroup;


echo "13- make myteam directory, read only for suer";
chmod u=r myteam/;	

echo "14- login out of user and login again";
su - islam;
exit;
#ctrl + d to logout or i can run exit
su - amiralsayed;

echo "15- try accessing mytemam/ >> failed because permessions btw";
cd myteam/;


echo "16 change mode of oldpassword file, 2 wayes";
sudo chmod 631 oldpasswd;
sudo chmod u=rw,g=rx,o=x oldpasswd;

umask 146;

umask 777;
mkdir testdir;
touch testfile;
ls -l testfile;
ls -ld testdir;




# 18 >> it will open in read only mode, and i can delete it normally
#19  >> for dir >> it will allow openning the direcoty, seeing metadata, for file, allow executing file.

