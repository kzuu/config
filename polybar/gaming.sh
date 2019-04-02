#!/bin/bash

paalla=$(grep color15 ~/.extend.Xresources | awk -F '#' '{print $2}')
pois=$(grep color13 ~/.extend.Xresources | awk -F '#' '{print $2}')

comptoni=$(if [ $(pgrep compton) > 0 ]; then echo "$paalla"; else echo "$pois"; fi)
bindit=$(if [ "$(xmodmap | grep control | awk -F ' ' '{print $2'})" = "Control_L" ]; then echo $paalla; else echo $pois; fi)

echo "%{F#$comptoni}%{F-}   |  %{F#$bindit}  %{F-}"




