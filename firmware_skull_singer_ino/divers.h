#ifndef divers_h
#define divers_h

//defines et macros
//#define DEBUG
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
#define CMD_ARRET     '0'
#define CMD_ATTENTE   '2'
#define CMD_OUVERT    '3'
#define CMD_MI_OUVERT '4'
#define CMD_FERME     '5'
#define NO_CMD        -1

//angles possibles d'ouverture de la machoire
#define ANGLE_1 0
#define ANGLE_2 40
#define ANGLE_3 80

#define PRECISION 20
#define A1A3 ANGLE_1 - ANGLE_3
#define A3A1 ANGLE_3 - ANGLE_1
#define A1A2 ANGLE_1 - ANGLE_2
#define A2A1 ANGLE_2 - ANGLE_1
#define A2A3 ANGLE_2 - ANGLE_3
#define A3A2 ANGLE_3 - ANGLE_2

#define PIN_SERVO 6
#define BAUD_RATE 9600

//definitions de structures et enumerations
enum sens_e { haut = 0, bas = 1};

//prototypes de fonctions publiques
void SkullInit();
int ecoute()  ;
void ouvre()  ;// ouvre la bouche
void miOuvre();// entre-ouvre la bouche
void ferme()  ;// ferme la bouche
void move( int incTime, const int angleCible, const char* texte);
void activeMoteur();
void coupeMoteur();

#endif
