#!/bin/bash
xmodmap -e "keycode 105 = Control_R"
xmodmap -e "keycode 37 = Control_L"

echo "Enable compton?"
select yn in "Yes" "No"; do
	case $yn in
		Yes ) compton -b; break;;
		No ) exit;;
	esac
done

echo "Disable OW binds?"
	select yn in "Yes" "No"; do
		case $yn in
			Yes ) xmodmap -e "keycode 105 = Control_R" && xmodmap -e "keycode 37 = Control_L"; break;;
			No ) exit;;
		esac
	done
