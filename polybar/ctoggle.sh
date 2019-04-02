#!/bin/bash

cpaalla=$(pgrep compton 2>&1)

if [[ -n $cpaalla ]]
	then
		killall compton
	else
		exec compton -b
fi
