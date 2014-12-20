#!/usr/bin/env bash

# if no arguments, compile all programs
if [[ $# -eq 0 ]] ; then
  for file in *.c; do
    echo "$file -o ${file%.c}"
    clang $file -o ${file%.c} -Wall -std=c11
  done
  exit
fi

filename=$1
output=${filename%.c}

clang $filename -o $output -Wall -std=c11

