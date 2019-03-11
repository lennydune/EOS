#!/usr/bin/env bash

IF=$1
FILE_TYPES=(${@:2})

COUNT_FILE_TYPES=()

for i in $(seq 0 $((${#FILE_TYPES[@]}-1))); do
	for j in $( ls $IF ); do
		EXTENSION="${j##*.}"
		if [ $EXTENSION == ${FILE_TYPES[$i]} ]; then
			COUNT_FILE_TYPES[$i]=$((${COUNT_FILE_TYPES[$i]}+1))
		fi
	done
done

for i in $(seq 0 $((${#FILE_TYPES[@]}-1))); do
	echo "${FILE_TYPES[$i]}: ${COUNT_FILE_TYPES[$i]}"
done