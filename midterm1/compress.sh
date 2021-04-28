#!/bin/bash/
echo "Enter the number of days since last access for compression."
read num
find . -mtime +$num -print >> filelist.txt
tar -cvf compressed.tar -T filelist.txt
rm filelist.txt
