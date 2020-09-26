#include "divers.h"

//prototypes de fonctions prives
void lancement();
void arret();
void attente();

void lancement();
void setup() //initialisation
{
	SkullInit();
}

void loop () //boucle principale
{
  char MSG = ecoute();
  switch(MSG)
  {
    case CMD_ARRET:	    { arret(); break; }
    case CMD_LANCEMENT:	{ lancement(); break; }
    case CMD_ATTENTE:	  { attente(); break; }
    case CMD_OUVERT:	  { ouvre(); break; }
    case CMD_MI_OUVERT:	{ miOuvre(); break; }
    case CMD_FERME:	  	{ ferme(); break; }
    case NO_CMD:        { /*Serial.println("NO CMD")*/; break; }
    default:            { Serial.println("UNKNOWN CMD"); break; }
  }
}

void lancement(){
	DEBUG_FN_START
  ferme();
  //TODO: décrire la séquence "somewhere over the rainbow"
/*  Début musique 235 ms
O 911 so
F 379 me
O 1086 whe
F 578 re
O 390 O
M 312 ver
O 575 the rai
M 403 ain
O 1162 bow
F 357 respiration
M 753 blue
O 864 bir
F 659 ds
O 1086 fl
F 1986 ly
M 1005 birds
O 794 fl
M 665 ly
O 426 O
F 412 ver
M 785 the rai
O 493 ai
F 469 n
O 321 bo
F 971 ow
O 1580 wh
F 1516 hy
M 591 oh
O 780 wh
F 747 hy
O 852 can
F 814 an’t
O 1159 ’t i
F 1159 iii
O 947 why
M 892 O
O 580 wh
F 981 hy
M 2452 can
O 3120 ’t iiiiii
F 2920 iiiiiii
Attente 192273 millisecondes */
	
  delay ( 235 );
  move( 0, 911,        ANGLE_3, ANGLE_2, "so"); // position ouvert so
  move( 0, 379,       ANGLE_2, ANGLE_3, "me");
  move( 900, 300,       ANGLE_3, ANGLE_1, "whe");
  move( 1086, 1100,     ANGLE_1, ANGLE_2, "re");
  move( 0, 500,         ANGLE_2, ANGLE_3, "b");
  move( 0, 450,         ANGLE_3, ANGLE_2, "la");
  move( 0, 400,         ANGLE_2, ANGLE_3, "b");
  move( 0, 350,         ANGLE_3, ANGLE_2, "la");
  move( 0, 300,         ANGLE_2, ANGLE_3, "b");
  move( 0, 250,         ANGLE_3, ANGLE_2, "la");
  move( 0, 200,         ANGLE_2, ANGLE_3, "b");
  move( 0, 150,         ANGLE_3, ANGLE_2, "la");
  move( 0, 100,         ANGLE_2, ANGLE_3, "p");
  move( 0, 100,         ANGLE_3, ANGLE_2, "ou");
  move( 0, 100,         ANGLE_2, ANGLE_3, "k");
  move( 0, 100,         ANGLE_3, ANGLE_2, "i");

	DEBUG_FN_END
}

void arret(){
	DEBUG_FN_START
  while(ecoute()==-1)
    delay(500);
	DEBUG_FN_END
}

void attente(){
	DEBUG_FN_START
   delay(5000);
	DEBUG_FN_END
}
