#!/bin/bash
#Commandes:
CMD_LANCEMENT="1"
CMD_ARRET="0"
CMD_ATTENTE="2"

#Chemins
SERIAL_PORT="/dev/ttyACM1"
AUDIO_FILE_PATH="/home/pi/sketchbook/over_the_skullbow/over_the_rain.mp3" 
PAUSE_TIME=5 #in seconds

function send { printf $1 > $SERIAL_PORT ;}

while [ 1 ];
do

	send $CMD_LANCEMENT  		# start skull sequence
	omxplayer $AUDIO_FILE_PATH -o local	# play music
	sleep $PAUSE_TIME 		# wait until restart
done
exit 0

