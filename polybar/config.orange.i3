;-------------------------------------------------
;                                                ;
;           Polybar config for my themes         ;
; 				                 ;
;                                                ;
;-------------------------------------------------


[colors]
;My colors are set from .Xresources to match everything else
my_background 	= ${xrdb:background}
my_foreground 	= ${xrdb:foreground}
;my_color0	= ${xrdb:color0}
my_color0 	= #80000000
my_color1	= ${xrdb:color1}
my_color2	= ${xrdb:color2}
my_color3	= ${xrdb:color3}
my_color4	= ${xrdb:color4}
my_color5	= ${xrdb:color5}
my_color6	= ${xrdb:color6}
my_color7	= ${xrdb:color7}
my_color8	= ${xrdb:color8}
my_color9	= ${xrdb:color9}
my_color10	= ${xrdb:color10}
my_color11	= ${xrdb:color11}
my_color12	= ${xrdb:color12}
my_color13	= ${xrdb:color13}
my_color14	= ${xrdb:color14}
my_color15	= ${xrdb:color15}

[bar/main_bar]
#;monitor = ${env:MONITOR:HDMI-1}
monitor = ${env:MONITOR:DVI-D-0}
bottom = true
width = 100%
height = 20
offset-x = 0
offset-y = 0
radius = 0.0
fixed-center = true


background = ${colors.my_color0}
foreground =  ${colors.my_foreground}

line-size = 2.5
line-color = ${colors.my_foreground}

border-size = 0
border-color = ${colors.my_color2}

padding-left = 0
padding-right = 0

module-margin-left = 0
module-margin-right = 0

font-2 = Bitstream Vera Mono:style=Roman:size=8;1
font-0 = Bitstream Vera Mono:style=Roman:size=8;1
font-1 = Bitstream Vera Mono:style=Roman:size=8;1


modules-left = i3 xwindow
modules-right = date 
#modules-right = musicinfo

tray-position = right
tray-padding = 9
tray-transparent = false
tray-offset-y = 0%
tray-offset-x = 0%
tray-maxsize = 18
tray-detached = false
tray-background = ${colors.my_color0}

wm-restack = i3

;override-redirect = true

[module/i3]
type = internal/i3
pin-workspaces = true
enable-scroll = false
wrapping-scroll = false

;valitsematon workspace
label-unfocused-background = ${colors.my_color0}
label-unfocused-foreground = ${colors.my_color8}

label-mode = %mode%
label-mode-padding = 2
label-mode-background = ${colors.my_color4}

;valittu workspace
label-focused = %name%
label-focused-foreground = ${colors.my_foreground}
label-focused-background = ${colors.my_color0}
label-focused-underline = ${colors.my_color13}
label-focused-padding = 2

label-unfocused = %name%
label-unfocused-padding = 2

; toisen ruudun valittu alaviiva
label-visible = %name%
label-visible-underline = ${colors.my_color8}
label-visible-padding = 4

label-urgent = %name%
label-urgent-foreground = ${colors.my_foreground}
label-urgent-background = ${colors.my_color0}
label-urgent-underline = ${colors.my_color8}
label-urgent-padding = 2

[module/date]

type = internal/date
interval = 5
date = "%d.%m.%Y"
time = %H:%M

format-prefix-foreground = ${colors.my_color14}
;format-underline = ${colors.my_color13}
format-underline =

label = %date% %time%

[settings]
screenchange-reload = true
;compositing-background = xor
;compositing-background = screen
;compositing-foreground = source
;compositing-border = over


[global/wm]
margin-top = 5
margin-bottom = 5

[module/xwindow]
type = internal/xwindow
label = %title:0:30:...%
label-padding = 10

;valittu ohjelma
label-foreground = ${colors.my_color7}

[bar/secondary_bar]
#;monitor = ${env:MONITOR:HDMI-1}
monitor = ${env:MONITOR:HDMI-0}
bottom = true
width = 100%
height = 20
offset-x = 0
offset-y = 0
radius = 0.0
fixed-center = true


background = ${colors.my_color0}
foreground =  ${colors.my_foreground}

line-size = 2.5
line-color = ${colors.my_color14}

border-size = 0
border-color = ${colors.my_color2}

padding-left = 0
padding-right = 0

module-margin-left = 0
module-margin-right = 0

font-2 = Bitstream Vera Mono:style=Roman:size=8;1
font-0 = Bitstream Vera Mono:style=Roman:size=8;1
font-1 = Bitstream Vera Mono:style=Roman:size=8;1


modules-left = i3 xwindow
modules-right = date 

tray-position = right
tray-padding = 9
tray-transparent = false
tray-offset-y = 0%
tray-offset-x = 0%
tray-maxsize = 18
tray-detached = false
tray-background = ${colors.my_background}

wm-restack = i3

;override-redirect = true
