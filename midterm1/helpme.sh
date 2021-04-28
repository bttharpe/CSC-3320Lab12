#!/bin/bash
echo "Please search for a command: "
read input
if grep "^ \+$input" mandatabase.txt; then
	man $input
else
	echo "sorry, I cannot help you"
fi
