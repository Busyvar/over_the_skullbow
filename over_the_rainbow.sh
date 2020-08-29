#!/bin/bash
#Commandes:
CMD_LANCEMENT="1"
CMD_ARRET="0"
CMD_ATTENTE="2"

#Chemins
SERIAL_PORT="/dev/ttyACM0"
AUDIO_FILE_PATH="Downloads/videoplayback.webm"

PAUSE_TIME=5

function send { printf $1 > $SERIAL_PORT ;}

while [ 1 ];
do
	send $CMD_LANCEMENT  		# start skull sequence
	#omxplayer $AUDIO_FILE_PATH 	# play music
	send $CMD_ARRET  		# stop sequence
	send $CMD_ATTENTE  		# start idling
	sleep $PAUSE_TIME 		# wait until restart
done
exit 0
