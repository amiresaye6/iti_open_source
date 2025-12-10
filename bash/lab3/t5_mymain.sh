#!/bin/bash

# 5. Write a script called mymail using for utility to send a mail to all users in the system.
# Note: write the mail body in a file called mtemplate.

body="./mtemplate"


for username in $(cut -d: -f1 /etc/passwd); do
    echo "Sending mail to user: $username"
    mailx -s "itiTask" "$username" < "$body" 
done

echo "Mail dispatch process complete."
