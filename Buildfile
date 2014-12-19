#!/usr/bin/env bash

filename=$1
output=${filename%.c}

clang $filename -o $output -Wall -std=c11

