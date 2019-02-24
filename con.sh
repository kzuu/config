#!/bin/bash
#xmodmap -e "keycode 37 = Control_R"
#xmodmap -e "keycode 105 = Control_L"
#xinput --set-prop 9 'libinput Accel Profile Enabled' 0, 1

echo "Disable compton?"
select yn in "Yes" "No"; do
	case $yn in
		Yes ) killall compton; break;;
		No ) exit;;
	esac
done

echo "Enable OW binds?"
select yn in "Yes" "No"; do
	case $yn in
		Yes ) xmodmap -e "keycode 37 = Control_R" && xmodmap -e "keycode 105 = Control_L"; break;;
		No ) exit;;
	esac
done

xinput list-props {1..50} 2>/dev/null | fgrep 'libinput Accel Profile Enabled ('
