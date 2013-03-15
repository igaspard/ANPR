#!/bin/bash

# Rename all the picture jpg name from 0, 1, 2, ... n at each folders.
# Author:   Gaspard Shen
# Mail:     syuyang@gmail.com

FOLDERS=$(ls)

for folder in $FOLDERS
do
    if [[ -d $folder ]]; then
        num=$(ls $folder/*.jpg | wc -l)
        echo $num, 
    fi
done
