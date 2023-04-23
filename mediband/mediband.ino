#define buzzerPin D4 // Set the pin for the buzzer

// Heart Rate Monitor - Start
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;
// Heart Rate Monitor - End

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);

  //Heart Rate Monitor - Start
  Setup_Hbeat_Sensor();
  //Heart Rate Monitor - End
}

void loop() {
  Siren_Buzz();
}
