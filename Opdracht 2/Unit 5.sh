#!/usr/bin/env bash

OF=$1

read -p "Enter your name: " NAME
if [[ $NAME == '' ]]; then
	NAME=$(whoami)
fi

echo $NAME
echo $OF

function getPass {
	read -s -p "Enter password: " PASSWORD
	echo
}

function getConf {
	read -s -p "Enter password again: " PASSWORD_CONF
	echo
	if [[ ! $PASSWORD_CONF == $PASSWORD ]]; then
		echo "Passwords do not match."
		getConf
	else
		savePass
	fi
}

function savePass {
	echo $NAME > $OF
	echo -n $PASSWORD | md5sum | cut -d' ' -f1 >> $OF
}

while [ true ]; do

	getPass

	if [[ ${#PASSWORD} < 8 ]]; then
		echo "Password has to contain at least eight characters."
		getPass
	fi
	if [[ ! $PASSWORD =~ [A-Z] ]]; then
		echo "Password has to contain at least one upper case character."
		getPass
	fi
	if [[ ! $PASSWORD =~ [a-z] ]]; then
		echo "Password has to contain at least one lower case character."
		getPass
	fi
	if [[ ! $PASSWORD =~ [0-9] ]]; then
		echo "Password has to contain at least one number."
		getPass
	fi

	getConf

	if [[ ! $PASSWORD_CONF == $PASSWORD ]]; then
		echo "Passwords do not match."
		getConf
	else
		break
	fi
done