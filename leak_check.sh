#!/bin/bash

executable=$1
#out_file=$2
out_file=valgrind_out.txt
rm -f $out_file
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$out_file $1
