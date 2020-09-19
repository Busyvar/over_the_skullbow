#include <Servo.h>
#define PIN_SERVO 6

//Commandes pour controler le depart et l'arret
#define CMD_LANCEMENT '1'
#define CMD_ARRET '0'
#define CMD_ATTENTE '2'

//angles possibles d'ouverture de la machoire
#define ANGLE_1 0
#define ANGLE_2 45
#define ANGLE_3 90

enum sens_e { haut = 0, bas = 1};

Servo myservo;  // création de l'objet myservo 


int increment = 1;       //incrément entre chaque position

#define STEP(x) if(ecoute()!= -1){ return; } \
                valInst+=x; \
                step (x);
#define REINIT step(- valInst); /*reset position à l'origine*/

char MSG = -1;

void step(int s);
void attente();
void move( int attente, int incTime, enum sens_e sens,int angleDepart, int angleCible);
void setup()
{
  Serial.begin(9600);
  while(!Serial){;}
  myservo.attach(PIN_SERVO);  // attache le servo au pin spécifié sur l'objet myservo
  //myservo.write(ANGLE_3);  
}

void loop ()
{
  int valInst = 0;
  REINIT
  switch(MSG)
  {
    case CMD_ARRET:{
      Serial.println("Stopping");// arret();
      break;
    }
    case CMD_LANCEMENT:{ lancement();
    break;
    }
    case CMD_ATTENTE:{// attente();
    break;
    }
    default:
    {
      Serial.println("NO CMD");
      ecoute();
      break;
    }
  }
  
  delay(200);
}

void step(int s)
{
  //Serial.println(__FUNCTION__);

}

void arret(){
  Serial.println(__FUNCTION__);
  while(ecoute()==-1)
    delay(500);
}

void attente(){
  Serial.println(__FUNCTION__);
   myservo.write(ANGLE_2);
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

  ecoute();
  return;      
}

int ecoute(){
  MSG = Serial.read();
  Serial.println(int (MSG));
  return MSG;
}

void move( int attente, int incTime, enum sens_e sens,int angleDepart, int angleCible)
{
  int pos = 0;
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
