#!/bin/bash/
echo "Please enter a keyword to search:"
read keyword
grep -o -i $keyword myexamfile.txt | wc -l