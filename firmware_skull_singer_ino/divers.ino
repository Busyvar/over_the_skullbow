#include <Servo.h>
#include "divers.h"

Servo myservo;

void affichePosition(int angle);
inline int ecoute()  { return Serial.read(); }
inline void ouvre()  { DEBUG_FN() myservo.write(ANGLE_1); }// ouvre la bouche
inline void miOuvre(){ DEBUG_FN() myservo.write(ANGLE_2); }// entre-ouvre la bouche
inline void ferme()  { DEBUG_FN() myservo.write(ANGLE_3); }// ferme la bouche

void SkullInit(){
  Serial.begin(BAUD_RATE);
  while(!Serial){;}
  myservo.attach(PIN_SERVO);  // attache le servo au pin spécifié sur l'objet myservo
}

void move( int incTime, int angleDepart, int angleCible, const char* texte)
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

void affichePosition(int angle){
	switch(angle){
		case ANGLE_1: Serial.print("[ ");break;
		case ANGLE_2: Serial.print("< ");break;
		case ANGLE_3: Serial.print("- ");break;
	}
}
