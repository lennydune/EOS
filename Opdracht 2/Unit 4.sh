#!/usr/bin/env bash

IF=$1
COMMAND=$2
OF="$IF/logs"

if [ ! -d $OF ]; then
	mkdir $OF
fi

if [ -f $OF/log.txt ]; then
	echo "" > $OF/log.txt
fi

for i in $( ls $IF ); do
	$COMMAND >> $OF/log.txt
done