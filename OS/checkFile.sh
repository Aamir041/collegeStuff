#!/bin/bash

path=$1

if [ -d $path ]; then
    echo "$path is a directory."
elif [ -f $path ]; then
    echo "$path is a regular file."
else
    echo "$path is something else."
fi
