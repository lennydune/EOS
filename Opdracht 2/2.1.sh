#!/usr/bin/env bash

IF=$1
OF="/home/lennard/Documents/Code/EOS/vakantieFotos"

if [ ! -d $OF ]; then
	mkdir $OF
fi
echo "Copying"
cp $IF/*vakantie* $OF
echo "Done"