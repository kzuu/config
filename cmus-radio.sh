#!/bin/bash

colornp=$(grep color1 ~/.extend.Xresources | awk -F '#' '{print $2}' | head -1)
colorno=$(grep color1 ~/.extend.Xresources | awk -F '#' '{print $2}' | head -1)
ikoni=""

if info=$(cmus-remote -Q 2> /dev/null); then
	title=$(echo "$info" | grep title | cut -d ':' -f -1 | cut -d ' ' -f 3-4)
	stream=$(echo "$info" | grep stream | cut -d ' ' -f 2-)
	vol=$(echo "$info" | grep vol_left | cut -d ' ' -f 3)
	
	if [[ $stream ]]; then
		echo "$ikoni $title  |  $stream  [vol: $vol]"
	else
		echo "%{F#$colornp}cmus not playing%{F-}"
	fi
		
else       
	echo "%{F#$colorno}cmus not running%{F-}"	
fi

