#!/usr/bin/env bash
# IF=$1
# FILE_TYPES=($2, $3, $4, $5, $6, $7)

IF="./bestanden"
FILE_TYPES=(txt pdf jpg png epub gif)

COUNT_FILE_TYPES=(0,0,0,0,0,0)

find $IF -name '*.$FILE_TYPES[1]' | sort -t_ -nk2,2 | tail -n1
