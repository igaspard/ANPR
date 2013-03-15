#!/bin/bash

# Rename all the picture jpg name from 0, 1, 2, ... n at each folders.
# Author:   Gaspard Shen
# Mail:     syuyang@gmail.com

FOLDERS=$(ls)

for folder in $FOLDERS
do
    if [[ -d $folder ]]; then
        JPG=$(ls $folder/*.jpg)
        i=0
        one=1
        for jpg in $JPG 
        do
            mv $jpg $folder/$i.jpg
            i=$(($i+$one))
        done
    fi
done

