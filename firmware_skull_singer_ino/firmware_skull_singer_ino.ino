#include <Stepper.h>

#define CMD_LANCEMENT '1'
#define CMD_ARRET '0'
#define CMD_ATTENTE '2'

#define STEP(x) if(ecoute()!= -1){ return; } \
                valInst+=x; \
                step (x);
#define REINIT step(- valInst); /*reset position à l'origine*/

int nombreDePas = 48*64;
char MSG = -1;

Stepper monMoteur(nombreDePas,9,11,10,6); // l'interface branchée sur les sorties 6 a 10  de l'Arduino

//int valeurActuelle;
//int valeurPrecedente;
void step(int s);
void attente();

void setup()
{
  Serial.begin(9600);
  monMoteur.setSpeed(8); // Vitesse Maxi de déplacement
  ecoute();    
}

void loop ()
{
  //valeurActuelle = map(analogRead(A0), 0, 1023, 0, 2050); // Pour faire 1 tour complet
  //valeurActuelle = analogRead(A0); // Pour le positionner en fonction du potentiomètre
  // monMoteur.step(valeurActuelle - valeurPrecedente);
  //valeurPrecedente = valeurActuelle;
  int valInst = 0;
  REINIT
  switch(MSG)
  {
    case CMD_ARRET:{
      Serial.println("Stopping"); arret();
      break;
    }
    case CMD_LANCEMENT:{ lancement();
      break;
    }
    case CMD_ATTENTE:{ attente();
      break;
    }
    default:
    {
      Serial.println("NO CMD");
      ecoute();
      break;
    }
  }
  
  delay(1000);
}

void step(int s)
{
  //Serial.println(__FUNCTION__);
  monMoteur.step(s);
}

void arret(){
  Serial.println(__FUNCTION__);
  monMoteur.setSpeed(1);
  while(ecoute()==-1)
    delay(500);
}

void attente(){
  Serial.println(__FUNCTION__);
  monMoteur.setSpeed(1);
  while(1){
   //STEP (200);
   //STEP (-200);
   delay(100);
   if(ecoute()!=-1) return; // for debug
  }
}

void lancement(){
  Serial.println(__FUNCTION__);
  //TODO: décrire la séquence "somewhere over the rainbow"
  monMoteur.setSpeed(8);
  /*delay(3000);
  STEP (500);
  STEP (-500);
  delay(1000);
  STEP (200);
  STEP (-200);
  delay(100);
  STEP (100);
  STEP (-100);*/
  ecoute();
  return;      
}

int ecoute(){
  MSG = Serial.read();
  Serial.println(int (MSG));
  return MSG;
}
