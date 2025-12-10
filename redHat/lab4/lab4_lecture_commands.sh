top >> will show the processes
top -u amiralsayed >> show processes of amir only

nice -n 10 -p top >> you can do this if it is above avrage  + nums
renice -n 10 -p 2529 >> this will change the priority of a process> range from -20 to +19

kill -l >> will list the 64 signals we can send with kill command
kill -9 >> sigkill >> forse kill this process
kill -9 >> sigterm >> terminate process the right way, if it has dependiants, will not close it.
kill -15 3232 >> terminate proces 3232
kill 3232 >> terminatin is the defualt
kill -SIGKTERM >> the same.

pkill bash >> kill process using process name >> kill any process named bash


ps -e >> list all system processs not real time.
ps -ef >> same but with more info
ps -fu amiralsayed >> get all the processes of amir user with full info

pgrep >> responsable for search in the processes
pgrep  bash >> return pid only of the processes contain bash >> like regex
pgrep -l bash >> return pid with username
pgrep -l ^ba >> return all what starts with ba
pgrep -l qd$ >> return all what nds with qd
pgrep -x ba >> exact match
pgrep -xl bas >> return the process with user info that is named bash "not expression"
pgrep -lu amiralsayed >> return all processes of user amir

jobs >> shows only applications and services only "jobs"

bg %1 >> backgroudn process on job number 1 "this number we got from the jobs table"
fg %1 >> forground process on job number 1 "aka stops the terminal again"

sleep 500 >> stops the terminal for 500 seconds
sleep 500 & >> sleep process but in background
sleep 30 && ls & >> runs ls after 30 seconds

wc /etc/passwd >>  gets line, word, characters count in a file
wc -l /etc/passwd >> get lines only, you can add -w or -c

grep >> text search inside a specific file
grep ^amir /etc/passwd >> get all the lines starts with amir in /etc/passwd file
grep H$ /etc/passwd >> wont return any thing, nothign ends with H cabital
grep -i H$ /etc/passwd >> -i ignre case
grep -ic H$ /etc/passwd >> will return the line number
grep -v ^amir /etc/passwd >> invers hte search >> return any thing but ^amir condition

find >> search for something in the entire hard drive

ls | grep ".txt" >> list all the filename sin the current direcorty, then pipeline the result to grep, search in it for any one that has ".txt" in it

echo "botato" | tr "a-z" "A-Z" >> translate pipeline >> change to upper case

wc -l < /etc/passwd >> here the bash itself will give hte /etc/passwd to the wc command
wc -l /etc/passwd >> wc itself will get the file data
