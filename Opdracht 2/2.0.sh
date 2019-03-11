#!/usr/bin/env bash

IF=$1
OF="/home/lennard/Documents/Code/EOS/afbeeldingen"

if [ ! -d $OF ]; then
	mkdir $OF
else
	echo "Copying"
	cp $IF/*.{jpg,png} $OF
	echo "Done"
fi