#include <Servo.h>

//defines et macros
#define PIN_SERVO 6
#define BAUD_RATE 9600

#define DEBUG
#ifdef DEBUG
#define DEBUG_FN(S) Serial.print(#S); Serial.println(__FUNCTION__);
#define DEBUG_FN_START DEBUG_FN(->)
#define DEBUG_FN_END   DEBUG_FN(<-)
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
#define CMD_FERME 		'5'
#define NO_CMD 				-1

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
inline void ouvre()  { DEBUG_FN_START myservo.write(ANGLE_1); DEBUG_FN_END }// ouvre la bouche
inline void miOuvre(){ DEBUG_FN_START myservo.write(ANGLE_2); DEBUG_FN_END }// entre-ouvre la bouche
inline void ferme()  { DEBUG_FN_START myservo.write(ANGLE_3); DEBUG_FN_END }// ferme la bouche
void attente();
void move( int attente, int incTime, enum sens_e sens,int angleDepart, int angleCible);

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
  //TODO: décrire la séquence "somewhere over the rainbow"
  myservo.write(ANGLE_3); // ferme la bouche
  delay(500);
  /*myservo.write(ANGLE_2);
  delay(911);
  myservo.write(ANGLE_3);
  delay(379);
  myservo.write(ANGLE_1);
  delay(1086);*/
  
  move( 500, 50, bas, ANGLE_3, ANGLE_2); // position ouvert so
  move( 911, 50, haut, ANGLE_2, ANGLE_3);// me
  move( 1086, 50, bas, ANGLE_3, ANGLE_1);// whe

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



void move( int attente, int incTime, enum sens_e sens,int angleDepart, int angleCible)
{
  int pos = 0;
  int increment = 1;       	//incrément entre chaque position
  delay(attente); 					//attente avant le mouvement
  if(sens == bas)
  {  
    for (pos =  angleDepart; pos >= angleCible; pos -= increment) {
      myservo.write(pos);              
      delay(incTime);   		//vitesse
    }
  }
  else if(sens == haut){
      for (pos =  angleDepart; pos <= angleCible; pos += increment) {
        myservo.write(pos);              
        delay(incTime);   	//vitesse
      }
  }
}
