
#include <Servo.h>

enum sens_e { ferme = 0, ouvre = 1};

#define ANGLE_1 0
#define ANGLE_3 70

Servo myservo;  // création de l'objet myservo 

int pin_servo = 6;       // Pin 6 sur lequel est branché le servo sur l'Arduino si vous utilisez un ESP32 remplacez le 6 par 4 et si vous utilisez un ESP8266 remplacez le 6 par 2

int pos = 0;             // variable permettant de conserver la position du servo
int angle_1 = 0;   //angle initial
int angle_3 = 70;   //angle final
int increment = 1;       //incrément entre chaque position
bool angle_actuel = false;//Envoi sur le port série la position courante du servomoteur

void move( int attente, int incTime, enum sens_e sens);

void setup() {
  Serial.begin(9600);                       
  while(!Serial){;} 
  myservo.attach(pin_servo);  // attache le servo au pin spécifié sur l'objet myservo
  
}

void loop() {
  /*
     delay(5000);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  so
    myservo.write(pos);              
    delay(70);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }*/
  move( 5000, 70, ouvre); // position ouvert so
  
  
  /*
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée me
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());
      } 
    }
  */
  move( 500, 50, ferme);
  
     delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  whe
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée re
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());

    }
  }
  
   delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  o
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée v
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());

    }
  }
  
   delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  e
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée r
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());
        
    delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  th
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée e
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());
        
  delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  rai
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée n
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());
        
  delay(500);
  for (pos = angle_3; pos >= angle_1; pos -= increment) { // position ouvert  bo
    myservo.write(pos);              
    delay(20);   // vitesse
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
     delay(500);
   for (pos = angle_1; pos <= angle_3; pos += increment) { //  position fermée w
    myservo.write(pos);              
    delay(50);                       
    if (angle_actuel) {
        Serial.println(myservo.read());
        
     

    }
  }           

    }
  }       

    }
  }  

    }
  }
  delay(500);
 }
void move( int attente, int incTime, enum sens_e sens)
{
  int pos;
  delay(attente);
  for (pos = sens == ouvre ? ANGLE_3 : ANGLE_1;
       pos >= sens == ouvre ? ANGLE_1 : ANGLE_3;
       pos -= increment) { // position ouvert  rai
    myservo.write(pos);              
    delay(incTime);   // vitesse
    if (angle_actuel) {
      Serial.println(myservo.read());
    }
  }
}
