#include <LoRandom.h>



#include <Servo.h>

#include <LCD-I2C.h>

String listeCarte[52] = {"1CO", "1CA", "1PI", "1TR", "2CO", "2CA", "2PI", "2TR", "3CO", "3CA", "3PI", "3TR", "4CO", "4CA", "4PI", "4TR", "5CO", "5CA", "5PI", "5TR", "6CO", "6CA", "6PI", "6TR", "7CO", "7CA", "7PI", "7TR", "8CO", "8CA", "8PI", "8TR", "9CO", "9CA", "9PI", "9TR", "10CO", "10CA", "10PI", "10TR", "11CO", "11CA", "11PI", "11TR", "12CO", "12CA", "12PI", "12TR", "13CO", "13CA", "13PI", "13TR"};

LCD_I2C lcd(0x27, 20, 4);

int bouton1 = 3;
int bouton2 = 5;
int bouton3 = 7;
int bouton4 = 9;
String etatGlobal = "";
Servo monServo;


void setup() {
  pinMode(bouton1, INPUT); // Initialiser le port d"entrée numérique en mode entrée
  Serial.begin(9600); // Initialiser la communication série
  monServo.attach(10);
  lcd.begin();
  lcd.display();
  lcd.backlight();



  resetScreen();
}

void resetScreen() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}
void giveCard() {
  for(int i=1; i<3; i++){
    monServo.write(i*30+90);
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
void loop() {

int etat1 = digitalRead(bouton1); // Lire l"état du bouton poussoir

if (etat1 == HIGH) {
  Serial.println("Le bouton1 est appuyé");
  etatGlobal = "Distribution";
  lcd.clear();


  lcd.setCursor(2, 0);
  lcd.print(etatGlobal);
  lcd.setCursor(2, 1);
  lcd.print(listeCarte[random(0,51)]);
  
  delay(500);
  giveCard();

  resetScreen();
}

int etat2 = digitalRead(bouton2); // Lire l"état du bouton poussoir

if (etat2 == HIGH) {
  Serial.println("Le bouton2 est appuyé");
  etatGlobal = "Stop";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(etatGlobal);
  delay(2000);

  resetScreen();
}

int etat3 = digitalRead(bouton3); // Lire l"état du bouton poussoir

if (etat3 == HIGH) {
  Serial.println("Le bouton3 est appuyé");
  etatGlobal = "Valider";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  delay(2000);

  resetScreen();
}

int etat4 = digitalRead(bouton4); // Lire l"état du bouton poussoir

if (etat4 == HIGH) {
  Serial.println("Le bouton4 est appuyé");
  etatGlobal = "Action";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  delay(2000);

  resetScreen();
}



}
