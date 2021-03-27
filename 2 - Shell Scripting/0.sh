#!/usr/bin/env bash

IF=$1
OF="$IF/afbeeldingen"

if [ ! -d $OF ]; then
	mkdir $OF
fi

cp $IF/*.{jpg,png} $OF
