#include <Servo.h>
//defines et macros
#define PIN_SERVO 6
#define BAUD_RATE 9600

#define DEBUG
#ifdef DEBUG
#define DEBUG_FN(S) Serial.print(#S); Serial.println(__FUNCTION__);
#define DEBUG_FN_START DEBUG_FN(=>)
#define DEBUG_FN_END   DEBUG_FN(<=)
#else
#define DEBUG_FN(S)
#define DEBUG_FN_START
#define DEBUG_FN_END  
#endif

//Commandes pour controler le depart et l'arret
#define CMD_LANCEMENT '1'
#define CMD_ARRET 		'0'
#define CMD_ATTENTE 	'2'
#define CMD_OUVERT 		'3'
#define CMD_MI_OUVERT '4'
#define CMD_FERME           '5'
#define NO_CMD             -1

//angles possibles d'ouverture de la machoire
#define ANGLE_1 0
#define ANGLE_2 45
#define ANGLE_3 90

//definitions de structures et enumerations
enum sens_e { haut = 0, bas = 1};

//variables globales
Servo myservo;  // création de l'objet myservo 
//prototypes de fonctions
inline int ecoute()  { return Serial.read(); }
inline void ouvre()  { DEBUG_FN() myservo.write(ANGLE_1); }// ouvre la bouche
inline void miOuvre(){ DEBUG_FN() myservo.write(ANGLE_2); }// entre-ouvre la bouche
inline void ferme()  { DEBUG_FN() myservo.write(ANGLE_3); }// ferme la bouche
void attente();
void move( int attente, int incTime, int angleDepart, int angleCible, const char* texte);
void affichePosition(int angle);


void affichePosition(int angle){
	switch(angle){
		case ANGLE_1: Serial.print("[ ");break;
		case ANGLE_2: Serial.print("< ");break;
		case ANGLE_3: Serial.print("- ");break;
	}
}

void setup() //initialisation
{
  Serial.begin(BAUD_RATE);
  while(!Serial){;}
  myservo.attach(PIN_SERVO);  // attache le servo au pin spécifié sur l'objet myservo
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


void move( int attente, int incTime, int angleDepart, int angleCible, const char* texte)
{
	unsigned long time = millis();
	const int ecartTotal = angleDepart - angleCible;
	const int precision = 24;
	const int pas = ecartTotal / precision; // 0-90/100
	const int fractionDuDelay = incTime / precision;
        enum sens_e sens = (ecartTotal > 0 )? bas : haut;
      Serial.print("anglDepart:");
      Serial.println(angleDepart);
      Serial.print("angleCible:");
      Serial.println(angleCible);
  delay(attente); 					//attente avant le mouvement
	affichePosition(angleDepart);
  if(sens == bas)
  {  
    for (int i=precision; i >= 0; i--) {
      Serial.print("position:");
      Serial.println((angleCible + (i * pas)));

      myservo.write(angleCible + (i * pas));              
      delay(fractionDuDelay);	//vitesse
	//Serial.print(".");
    }
    
    /*
    délai / 100
    mouvement / 100
    andleDepart(90) -> (0..100/100)ecart -> angleCible(0)
    */
  }
  else if(sens == haut){
    for (int i=0; i <= precision; i++) {
      Serial.print("position:");
      Serial.println((angleCible - (i * pas)));
      myservo.write(angleCible - (i * pas));
      delay(fractionDuDelay);   		//vitesse
      //Serial.print(".");
    }
  }
	time = (time - millis()) * -1;
	affichePosition(angleCible);
	Serial.print(texte);
	Serial.print(" ");
	Serial.print(time);
	Serial.println("ms");
}

