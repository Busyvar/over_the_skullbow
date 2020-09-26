#include "divers.h"

//prototypes de fonctions prives
void lancement();
void arret();
void attente();
void lancement();
void arret();
void attente();
void testUnitaireMouvement();

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
    case CMD_LANCEMENT:	{
      activeMoteur();
      lancement();
      coupeMoteur(); 
    break; }
    case CMD_ATTENTE: {
      activeMoteur();
      attente();
      coupeMoteur();
    break; }
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
  delay ( 200 ); // pre-buffering
  delay ( 235 );
  move( 911,  ANGLE_1, "so"); // O
  move( 379,  ANGLE_3, "me"); // F
  move( 1086, ANGLE_1, "whe"); //O
  move( 578,  ANGLE_3, "re"); //F
  move( 390,  ANGLE_1, "o"); //O
  move( 312,  ANGLE_2, "ver"); //M
  move( 575,  ANGLE_1, "the rai"); //O
  move( 403,  ANGLE_2, "ain"); //M
  move( 1162, ANGLE_1, "bow"); //O
  move( 357,  ANGLE_3, "respiration"); //F
  move( 753,  ANGLE_2, "blue"); //M
  move( 864,  ANGLE_1, "bir"); //O
  move( 659,  ANGLE_3, "ds"); //F
  move( 1086, ANGLE_1, "fl"); //O
  move( 1986, ANGLE_3, "ly"); //F
  move( 1005, ANGLE_2, "birds"); //M
  move( 794,  ANGLE_1, "fl"); //O
  move( 665,  ANGLE_2, "ly"); //M
  move( 426,  ANGLE_1, "o"); //O
  move( 412,  ANGLE_3, "ver"); //F
  move( 785,  ANGLE_2, "the rai"); //M
  move( 493,  ANGLE_1, "ai"); //O
  move( 469,  ANGLE_3, "n"); //F
  move( 321,  ANGLE_1, "bo"); //O
  move( 971,  ANGLE_3, "ow"); //F
  move( 1580, ANGLE_1, "wh"); //O
  move( 1516, ANGLE_3, "hy"); //F
  move( 591,  ANGLE_2, "oh"); //M
  move( 780,  ANGLE_1, "wh"); //O
  move( 747,  ANGLE_3, "hy"); //F
  move( 852,  ANGLE_1, "can"); //O
  move( 814,  ANGLE_3, "ant"); //F
  move( 1159, ANGLE_1, "t i"); //O
  move( 1159, ANGLE_3, "iii"); //F
  move( 947,  ANGLE_1, "why"); //O
  move( 892,  ANGLE_2, "oh"); //M
  move( 580,  ANGLE_1, "wh"); //O
  move( 981,  ANGLE_3, "hy"); //F
  move( 2452, ANGLE_2, "can"); //M
  move( 1120, ANGLE_1, "t iiiii"); //O
  delay ( 2000 );
  move( 2920, ANGLE_3, "iiiiiiii"); //F
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
  //testUnitaireMouvement();
  delay(5000);
  DEBUG_FN_END
}
void testUnitaireMouvement(){
  move( 1000, ANGLE_2, "bas");
  move( 1000, ANGLE_3, "om");
  move( 1000, ANGLE_1, "baas");
  move( 1000, ANGLE_2, "o");
  move( 1000, ANGLE_1, "aaaah");
  move( 1000, ANGLE_3, "ommmmm");
}
