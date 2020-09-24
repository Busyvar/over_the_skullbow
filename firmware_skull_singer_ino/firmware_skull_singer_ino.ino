#include <Servo.h>

//defines et macros
#define PIN_SERVO 6
#define BAUD_RATE 9600
//Commandes pour controler le depart et l'arret
#define CMD_LANCEMENT '1'
#define CMD_ARRET '0'
#define CMD_ATTENTE '2'
#define NO_CMD -1

//angles possibles d'ouverture de la machoire
#define ANGLE_1 0
#define ANGLE_2 45
#define ANGLE_3 90

#define STEP(x) if(ecoute()!= NO_CMD){ return; }

//definitions de structures et enumerations
enum sens_e { haut = 0, bas = 1};

//variables globales
Servo myservo;  // création de l'objet myservo 

//prototypes de fonctions
inline int ecoute(){ return Serial.read(); }
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
    case CMD_ARRET:{ arret(); break; }
    case CMD_LANCEMENT:{ lancement(); break; }
    case CMD_ATTENTE:{ attente(); break; }
    case NO_CMD:{ 
      Serial.println("NO CMD");
	  break;
	}
    default:
    {
      Serial.println("UNKNOWN CMD");
      break;
    }
  }
  ecoute();
  
  delay(200);
}

void arret(){
  Serial.println(__FUNCTION__);
  while(ecoute()==-1)
    delay(500);
}

void attente(){
  Serial.println(__FUNCTION__);
   //myservo.write(ANGLE_2);
   delay(5000);
}

void lancement(){
  Serial.println(__FUNCTION__);
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

}


void move( int attente, int incTime, enum sens_e sens,int angleDepart, int angleCible)
{
  int pos = 0;
  int increment = 1;       //incrément entre chaque position
  delay(attente);
  if(sens == bas)
  {  
    for (pos =  angleDepart; pos >= angleCible; pos -= increment) {
      myservo.write(pos);              
      delay(incTime);   // vitesse
    }
  }
  else if(sens == haut){
      for (pos =  angleDepart; pos <= angleCible; pos += increment) {
        myservo.write(pos);              
        delay(incTime);   // vitesse
      }
  }
  else{
    //c'est de la m
  }
}
