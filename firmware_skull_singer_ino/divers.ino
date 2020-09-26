#include <Servo.h>
#include "divers.h"

Servo myservo;

void affichePosition(int angle);
inline int ecoute()  { return Serial.read(); }
inline void ouvre()  { DEBUG_FN() myservo.write(ANGLE_1); }// ouvre la bouche
inline void miOuvre(){ DEBUG_FN() myservo.write(ANGLE_2); }// entre-ouvre la bouche
inline void ferme()  { DEBUG_FN() myservo.write(ANGLE_3); }// ferme la bouche
inline void activeMoteur(){ myservo.attach(PIN_SERVO);}
inline void coupeMoteur(){ myservo.detach();}

void SkullInit(){
  Serial.begin(BAUD_RATE);
  while(!Serial){;}
}


void move( int incTime, const int angleCible, const char* texte)
{
  static int positionPrecedente = ANGLE_3;
  const int ecartTotal = positionPrecedente - angleCible;
  const int precision = PRECISION;
  const int pas = ecartTotal / precision; // 0-90/100
  const float fractionDuDelay = incTime / precision;
  unsigned long time = millis();
  
  Serial.print(positionPrecedente);
  Serial.print(" vers ");
  Serial.println(angleCible);
  Serial.println(pas);
  affichePosition(positionPrecedente);

  for (int i=positionPrecedente; i != angleCible; i -= pas) {
    Serial.print("position:");
    Serial.println(i);
    myservo.write(i);
    delay(fractionDuDelay);//vitesse
  }
  myservo.write(angleCible);

  positionPrecedente = angleCible;
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
