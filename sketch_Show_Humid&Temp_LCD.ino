#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int lm35pin = A5;

float data;
float temp;

void setup() {

  lcd.begin(16, 2);


  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:


  data = dht.readHumidity();
  temp = dht.readTemperature();

  lcd.print("temp = ");
  lcd.print(temp);
  lcd.print("c");
  lcd.setCursor(0, 1);
  lcd.print("humid:");
  lcd.print(data);

  Serial.print("temp :");
  Serial.print(temp);
  Serial.println("*C");
  Serial.print("humid :");

  Serial.print(data);
  Serial.println("%");
  Serial.println("");


  if (temp > 28) {
    digitalWrite(6, HIGH);

    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);

    digitalWrite(6, LOW);
  }
  delay(2000);
  lcd.clear();
}
