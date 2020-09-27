#!/bin/bash
#Commandes:
CMD_LANCEMENT="1"
CMD_ARRET="0"
CMD_ATTENTE="2"

#Chemins
SERIAL_PORT="/dev/ttyACM*"
AUDIO_FILE_PATH="/home/pi/sketchbook/over_the_skullbow/over_the_rain.mp3" 
PAUSE_TIME=5 #temps en seconde après la chanson

function send { printf $1 > $SERIAL_PORT ;}

#stty -F $SERIAL_PORT ospeed 9600 # fix baudrate
#chmod 777 $SERIAL_PORT

while [ 1 ];
do

head -c 1 $SERIAL_PORT &
send $CMD_ATTENTE
sleep 5


	send $CMD_LANCEMENT  		# start skull sequence
	omxplayer $AUDIO_FILE_PATH -o local	# play music
	sleep $PAUSE_TIME 		# wait until restart
done
exit 0
