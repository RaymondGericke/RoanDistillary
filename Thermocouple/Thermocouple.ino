#include "max6675.h"

int soPin = 3;// SO=Serial Out
int csPin = 4;// CS = chip select CS pin
int sckPin = 5;// SCK = Serial Clock pin
MAX6675 thermo(sckPin, csPin, soPin);// create instance object of MAX6675
void setup() {
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("MAX6675 TEMP: ");
}

void loop() {
  Serial.print("C = ");
  Serial.print(thermo.readCelsius());
  Serial.print(" F = ");
  Serial.println(thermo.readFahrenheit());
  delay(1000);
}
