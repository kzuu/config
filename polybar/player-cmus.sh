#!/bin/sh

if info=$(cmus-remote -Q 2> /dev/null); then
	status=$(echo "$info" | grep -v "set " | grep -v "tag " | grep "status " | cut -d ' ' -f 2)

	if [ "$status" = "playing" ] || [ "$status" = "paused" ]; then
		artist=$(echo "$info" | grep -v 'set ' | grep " stream " | cut -d' ' -f2-)

		if [ "$status" = "playing" ]; then
			echo "$artist"
		elif [ "$status" = "paused" ]; then
			echo "$artist"
		else
			echo ""
		fi
	else
		echo ""
	fi
else
	echo ""
fi
