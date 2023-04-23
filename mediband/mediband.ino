#define buzzerPin D4 // Set the pin for the buzzer
#define THRESHOLD_ACCEL 11 // accelerometer threshold for detecting a fall
#define THRESHOLD_GYRO 11 // gyro threshold for detecting a fall

#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

MAX30105 particleSensor;
Adafruit_MPU6050 mpu;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);

  // Setup_Hbeat_Sensor();
  Setup_FallSensor();
}

void loop() {
  // Start Detecting Fall
  Detect_Fall();
}
