#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <path>"
    exit 1
fi

path=$1

num_dirs=$(find "$path" -type d | wc -l)
num_regular=$(find "$path" -type f | wc -l)


# echo "processed all the directories from the path $path"
echo "There were $num_dirs directories."
echo "There were $num_regular regular files."

