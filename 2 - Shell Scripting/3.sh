#!/usr/bin/env bash

IF=$1
OF="$IF/pngBestanden"

if [ ! -d $OF ]; then
	mkdir $OF
fi

for i in $( ls $IF ); do
	FILE_NAME="${i%.*}"
	EXTENSION="${i##*.}"
	if [ $EXTENSION == "jpg" ]; then
		convert -resize 128x128 $IF/$FILE_NAME.jpg $OF/$FILE_NAME.png
	fi
done