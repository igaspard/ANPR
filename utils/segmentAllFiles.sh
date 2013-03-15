#!/bin/bash
FILES=./test/*.jpg
FILES1=./test/*.JPG
for f in $FILES
do
    echo "Processing $f file..."
    # take action on each file. $f store current file name
    ./build/ANPR $f
done

for f in $FILES1
do
    echo "Processing $f file..."
    # take action on each file. $f store current file name
    ./build/ANPR $f
done
