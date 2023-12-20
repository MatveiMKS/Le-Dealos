#include <Servo.h>

#include <LCD-I2C.h>


LCD_I2C lcd(0x27, 20, 4);

int bouton1 = 3;
int bouton2 = 5;
int bouton3 = 7;
int bouton4 = 9;
String etatGlobal = "";
Servo monServo;


void setup() {
pinMode(bouton1, INPUT); // Initialiser le port d'entrée numérique en mode entrée
Serial.begin(9600); // Initialiser la communication série
monServo.attach(10);
  lcd.begin();
  lcd.display();
  lcd.backlight();



  lcd.setCursor(5, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}

void loop() {

int etat1 = digitalRead(bouton1); // Lire l'état du bouton poussoir

if (etat1 == HIGH) {
  Serial.println("Le bouton1 est appuyé");
  etatGlobal = "Tirer";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  
  
  
  delay(1000);
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


  
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}

int etat2 = digitalRead(bouton2); // Lire l'état du bouton poussoir

if (etat2 == HIGH) {
  Serial.println("Le bouton2 est appuyé");
  etatGlobal = "Stop";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}

int etat3 = digitalRead(bouton3); // Lire l'état du bouton poussoir

if (etat3 == HIGH) {
  Serial.println("Le bouton3 est appuyé");
  etatGlobal = "Valider";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}

int etat4 = digitalRead(bouton4); // Lire l'état du bouton poussoir

if (etat4 == HIGH) {
  Serial.println("Le bouton4 est appuyé");
  etatGlobal = "Action";
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(etatGlobal);
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Que voulez");
  lcd.setCursor(1, 1);
  lcd.print("vous faire?");
}



}