#!/usr/bin/env bash

IF=$1
OF="$IF/vakantieFotos"

if [ ! -d $OF ]; then
	mkdir $OF
fi

cp $IF/*vakantie* $OF