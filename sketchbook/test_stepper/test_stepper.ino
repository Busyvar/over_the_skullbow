#include <Stepper.h>
  int nombreDePas = 48*64;
  Stepper m(nombreDePas,9,11,10,6);

void setup(){
  m.setSpeed(9);
  //m.step(-15);
  //delay(2);
  
}
void loop(){
  /*int delay_ms=50;
  int time=0;
  while(time<5000){
  delay(delay_ms);
  m.step(5);
  Serial.println("w");
  time += delay_ms;
  }
  delay(1000);*/
  m.step(400);
  m.step(-400);
  
}
