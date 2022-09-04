#!/bin/bash

total_arg=$#

if [ $total_arg -eq 0 ];
  then
    printf "need one arg at least! 😥\n"
    exit 0
fi

FILE=$1

if [ ! -f "$FILE" ]; then
    printf "path not a file! 😥\n"
    exit 0 
fi


file_name_type=$(basename "$FILE")
file_name=${file_name_type%.*}

echo $file_name


BUILD_DIR="./build"

if [ ! -d "$BUILD_DIR" ];
then
    mkdir $BUILD_DIR
fi

g++ -g $FILE -o  $BUILD_DIR/$file_name && $BUILD_DIR/$file_name 
