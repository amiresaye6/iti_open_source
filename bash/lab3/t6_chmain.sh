#!/bin/bash

# 6. Write a script called chkmail to check for new mails every 10 seconds.
# Note: mails are saved in /var/mail/username.

USERNAME=`whoami`
MAILBOX_FILE="/var/mail/$USERNAME"

if [[ ! -f "$MAILBOX_FILE" ]]; then
    echo "Error: Mailbox file not found at $MAILBOX_FILE."
    exit 1
fi

INITIAL_SIZE=$(stat -c %s "$MAILBOX_FILE")

while true; do
    
    CURRENT_SIZE=$(stat -c %s "$MAILBOX_FILE")
    
    if [[ "$CURRENT_SIZE" -gt "$INITIAL_SIZE" ]]; then
        echo "NEW MAIL DETECTED at $(date)! Size increased from $INITIAL_SIZE to $CURRENT_SIZE."
        INITIAL_SIZE="$CURRENT_SIZE"
    
    elif [[ "$CURRENT_SIZE" -lt "$INITIAL_SIZE" ]]; then
        INITIAL_SIZE="$CURRENT_SIZE"
    fi
    
    sleep 10
done
