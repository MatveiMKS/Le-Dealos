

#include <Servo.h>

#include <LCD-I2C.h>

#include <SoftwareSerial.h>

LCD_I2C lcd(0x27, 20, 4);

int bouton1 = 12;
int bouton2 = 13;
String etatGlobal = "";
String strPlay = "";
String strScore = "";
Servo monServo;
SoftwareSerial GM65(3,4);

int playerScore[6] = {0, 0, 0, 0, 0, 0};
int possedeAs[5] = {0, 0, 0, 0,0};
int carte[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int enJeu[5] = {0,0,0,0,0};
int nbPlayer;
boolean jeu;
int meilleurJoueur;




void setup(){
  pinMode(bouton1, INPUT); // Initialiser le port d"entrée numérique en mode entrée
  Serial.begin(9600); // Initialiser la communication série
  monServo.attach(7);
  lcd.begin();
  lcd.display();
  lcd.backlight();


  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Nb joueurs ?");
  lcd.setCursor(0, 1);
  lcd.print("1   2   3   4");

  GM65.begin(9600);
}

int vainqueur(int nbPlayer){
  Serial.println(nbPlayer);
  for (int i = 0; i<nbPlayer; i++){
    if ((playerScore[nbPlayer] < playerScore[i]) && (playerScore[i]< 22)){
      //Serial.println("Joueur " + String(i) + " a gagne");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("P" + String(i) + " a");
      lcd.setCursor(1, 1);
      lcd.print("gagné");
    }
  }
  
}

int lectureCode(){
  String barcode = GM65.readStringUntil(' ');
  Serial.println(barcode);
  if ((barcode.charAt(0) == 'd') || (barcode.charAt(0) == "v") || (barcode.charAt(0) == "d")){
    return 10;
  }
  else{
    return int(barcode.charAt(0));
  }
}


void resetScreen(int play) {
  lcd.clear();
  lcd.setCursor(0, 0);
  strPlay = "P" + String(play);
  lcd.print(strPlay + "   Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}

void afficheScore(int play, int score){
  lcd.clear();
  lcd.setCursor(0, 0);
  strPlay = "P" + String(play);
  strScore = String(score);
  lcd.print(strPlay + "   Votre score");
  lcd.setCursor(1, 1);
  lcd.print("est " + strScore);
}



void giveCard() {
  for (int i = 1; i < 3; i++) {
    monServo.write(i * 30 + 90);
    delay(20);
  }
  monServo.write(130);
  delay(300);
  monServo.write(90);
  delay(100);
  monServo.write(0);
  delay(180);
  monServo.write(90);
}


void loop(){
  jeu = true;
  //Serial.println("Combien de joueurs etes vous");
  //while (Serial.available() == 0) {}
  //int nbPlayer = Serial.parseInt();


    int etat1 = 0;
    int etat2 = 0;
 
  while(etat2 == LOW){
    int etat1 = digitalRead(bouton1);
    int etat2 = digitalRead(bouton2);
    if (etat1 == HIGH) {
      nbPlayer += 1;
    }
    if (nbPlayer >=4){
      nbPlayer = 0;
    }
    delay(250);
  }

  for (int i=0; i<nbPlayer+1; i++){
    playerScore[i] = 0;
    //playerScore[i] += carte[random(0,11)];
    //playerScore[i] += carte[random(0,11)];
    playerScore[i] += lectureCode();
    giveCard();
    playerScore[i] += lectureCode();
    giveCard();
    //Serial.println("Le score du joueur " +String(i) +" est " + String(playerScore[i]));
    afficheScore(i, playerScore[i]);
    enJeu[i] = 1;
    delay(1000);
  }
  
  while (jeu == true){
    for (int i=0; i<nbPlayer+1; i++){
     
      if (enJeu[i] == 1){
        resetScreen(i);
        //Serial.println("Voulez-vous jouer joueur " + String(i));
        //while (Serial.available() == 0) {}
        //enJeu[i] = Serial.parseInt();
        int etat1 = 0;
        int etat2 = 0;
        while (etat1 == 0 || etat2 == 0) {
          int etat1 = digitalRead(bouton1);
          int etat2 = digitalRead(bouton2);
        }
        if (etat1 == 1){
          //playerScore[i] += carte[random(0,11)];
          playerScore[i] += lectureCode();
          giveCard();
          //Serial.println("Le score du joueur " +String(i) +" est " + String(playerScore[i]));
          afficheScore(i, playerScore[i]);
          if (playerScore[i] > 21){
            enJeu[i]= 0;
            //Serial.println("Le joueur " + String(i) + " a perdu");

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("P" + String(i) + " a");
            lcd.setCursor(1, 1);
            lcd.print("perdu");
          }
          if (playerScore[i] == 21){
            enJeu[i]= 0;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("P" + String(i) + " a");
            lcd.setCursor(1, 1);
            lcd.print("gagné");
        }
      }
      else{
        enJeu[i] = 0;
      }
    }
    if ((enJeu[0] == 0) && (enJeu[1] == 0) && (enJeu[2] == 0) && (enJeu[3] == 0) && (enJeu[4] == 0)){
      //Serial.println("La partie est finie");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fin de la");
      lcd.setCursor(1, 1);
      lcd.print("partie");
      jeu = false;
      vainqueur(nbPlayer);
      
    }
   }
  }
}
