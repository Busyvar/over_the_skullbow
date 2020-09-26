#include "divers.h"

//prototypes de fonctions prives
void lancement();
void arret();
void attente();

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
  move( 911,        ANGLE_3, ANGLE_1, "so"); // O
  move( 379,       ANGLE_1, ANGLE_3, "me"); // F
  move( 1086,       ANGLE_3, ANGLE_1, "whe"); //O
  move( 578,     ANGLE_1, ANGLE_3, "re"); //F
  move( 390,         ANGLE_3, ANGLE_1, "o"); //O
  move( 312,         ANGLE_1, ANGLE_2, "ver"); //M
  move( 575,         ANGLE_2, ANGLE_1, "the rai"); //O
  move( 403,         ANGLE_1, ANGLE_2, "ain"); //M
  move( 1162,         ANGLE_2, ANGLE_1, "bow"); //O
  move( 357,         ANGLE_1, ANGLE_3, "respiration"); //F
  move( 753,         ANGLE_3, ANGLE_2, "blue"); //M
  move( 864,         ANGLE_2, ANGLE_1, "bir"); //O
  move( 659,         ANGLE_1, ANGLE_3, "ds"); //F
  move( 1086,         ANGLE_3, ANGLE_1, "fl"); //O
  move( 1986,         ANGLE_1, ANGLE_3, "ly"); //F
  move( 1005,         ANGLE_3, ANGLE_2, "birds"); //M
  move( 794,        ANGLE_2, ANGLE_1, "fl"); //O
  move( 665,       ANGLE_1, ANGLE_2, "ly"); //M
  move( 426,       ANGLE_2, ANGLE_1, "o"); //O
  move( 412,     ANGLE_1, ANGLE_3, "ver"); //F
  move( 785,         ANGLE_3, ANGLE_2, "the rai"); //M
  move( 493,         ANGLE_2, ANGLE_1, "ai"); //O
  move( 469,         ANGLE_1, ANGLE_3, "n"); //F
  move( 321,         ANGLE_3, ANGLE_1, "bo"); //O
  move( 971,         ANGLE_1, ANGLE_3, "ow"); //F
  move( 1580,         ANGLE_3, ANGLE_1, "wh"); //O
  move( 1516,         ANGLE_1, ANGLE_3, "hy"); //F
  move( 591,         ANGLE_3, ANGLE_2, "oh"); //M
  move( 780,         ANGLE_2, ANGLE_1, "wh"); //O
  move( 747,         ANGLE_1, ANGLE_3, "hy"); //F
  move( 852,         ANGLE_3, ANGLE_1, "can"); //O
  move( 814,         ANGLE_1, ANGLE_3, "ant"); //F
  move( 1159,        ANGLE_3, ANGLE_1, "t i"); //O
  move( 1159,       ANGLE_1, ANGLE_3, "iii"); //F
  move( 947,       ANGLE_3, ANGLE_1, "why"); //O
  move( 892,     ANGLE_1, ANGLE_2, "oh"); //M
  move( 580,         ANGLE_2, ANGLE_1, "wh"); //O
  move( 981,         ANGLE_1, ANGLE_3, "hy"); //F
  move( 2452,         ANGLE_3, ANGLE_2, "can"); //M
  move( 3120,         ANGLE_2, ANGLE_1, "t iiiii"); //O
  move( 2920,         ANGLE_1, ANGLE_3, "iiiiiiii"); //F
  //delay (192273 ) ; //ATTENTE 3 MIN
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
