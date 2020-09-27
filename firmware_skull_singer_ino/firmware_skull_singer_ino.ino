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
  move( 711,  ANGLE_2, "so"); // M
  delay ( 200 );
  move( 379,  ANGLE_3, "me"); // F
  delay ( 0 );
  move( 400, ANGLE_2, "whe"); //M
  delay ( 686 );
  move( 500,  ANGLE_3, "re"); //F
  delay ( 78 );
  move( 100,  ANGLE_2, "o"); //M
  delay ( 290 );
  move( 50,  ANGLE_3, "V"); //F
  delay ( 50 );
  move( 150,  ANGLE_2, "ver"); //M
  delay (62 );
  move ( 50 , ANGLE_3, "t"); //F
  delay (50);
  move( 275,  ANGLE_2, "the rai"); //M
  delay ( 303 );
  move( 50,  ANGLE_3, "ain"); //F
  delay ( 0 );
  move( 362, ANGLE_1, "bow"); //O
  delay ( 1000 );
  move( 257,  ANGLE_3, "respiration"); //F
  delay ( 100 );
  move( 353,  ANGLE_2, "blue"); //M
  delay ( 300 );
  move( 600,  ANGLE_3, "bIR"); //O
  delay ( 423 ); 
  move( 50,  ANGLE_3, "ds"); //F
  delay ( 0 );
  move( 486, ANGLE_1, "fl"); //O
  delay ( 900 );
  move( 1086, ANGLE_3, "ly"); //F
  delay ( 400 );
  move( 205, ANGLE_2, "birds"); //M
  delay ( 700 );
  move( 100, ANGLE_3, "ds"); //F
  delay ( 0 );
  move( 359,  ANGLE_1, "flY"); //O
  delay ( 800 );
  move( 200,  ANGLE_3, "RESPI"); //F
  delay ( 100 );
  move( 226,  ANGLE_2, "ove"); //M
  delay ( 200 );
  move( 100,  ANGLE_3, "v"); //F
  delay ( 0);
  move( 112,  ANGLE_2, "ver"); //M
  delay ( 100 );
  move( 100,  ANGLE_3, "T"); //F
  delay ( 0 );
  move( 678,  ANGLE_2, "the rai"); //M
  delay ( 500 ); 
  move( 50,  ANGLE_3, "n"); //F 	
  delay (0 );
  move( 321,  ANGLE_1, "bo"); //M
  delay ( 500 );
  move( 71,  ANGLE_3, "ow"); //F 	
  delay ( 0 ); 				
  move( 1080, ANGLE_1, "wh"); //O
  delay ( 1000 );
  move( 816, ANGLE_3, "hy"); //F
  delay ( 200 );
  move( 491,  ANGLE_2, "oh"); //M
  delay ( 100 );
  move( 780,  ANGLE_1, "wh"); //O
  delay ( 400 );
  move( 347,  ANGLE_3, "hy"); //F
  delay ( 0);
  move( 852,  ANGLE_1, "can"); //O
  delay ( 400 );
  move( 314,  ANGLE_3, "ant"); //F
  delay ( 100 );
  move( 1159, ANGLE_1, "t i"); //O
  delay ( 500 );
  move( 559, ANGLE_3, "iii"); //F
  delay ( 100 );
  move( 647,  ANGLE_1, "why"); //O
  delay ( 300 );
  move( 692,  ANGLE_2, "oh"); //M
  delay ( 200 );
  move( 580,  ANGLE_1, "wh"); //O
  delay ( 300 );
  move( 581,  ANGLE_3, "hy"); //F
  delay ( 100 );
  move( 1452, ANGLE_2, "can"); //M
  delay ( 1000 );
  move( 1120, ANGLE_1, "t iiiii"); //O
  delay ( 2850 ); 			
  move(1920, ANGLE_3, "iiiiiiii"); //F
  delay (1000 );
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
