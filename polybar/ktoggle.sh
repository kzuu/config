#!/bin/bash

if [[ $(xmodmap | grep control | awk -F ' ' '{print $2'}) == "Control_L" ]]
	then
		xmodmap -e "keycode 37 = Control_R" && xmodmap -e "keycode 105 = Control_L"
	else
		xmodmap -e "keycode 105 = Control_R" && xmodmap -e "keycode 37 = Control_L"
fi
