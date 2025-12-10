#!/bin/bash

case "$1" in
	"-l")
		echo "long list command"
	;;
	"-R")
		echo "Recursive listing"
	;;
	"-a")
		echo "all info command"
	;;
	"-i")
		echo "show inode command"
	;;
	"-h")
		echo "human redable data command"
	;;
	*)
		echo "Invalid option: $1"
	;;
esac
