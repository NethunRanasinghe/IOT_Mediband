#define buzzerPin D4 // Set the pin for the buzzer
<<<<<<< HEAD
#define WIFI_SSID "Dialog 4G 827"
#define WIFI_PASSWORD "VillAiN248"
#define API_KEY "AIzaSyAWtQRLx_Sovaq0VVuuv980hgz7IPlJ_8E"
#define USER_EMAIL "testuser1@test.com"
#define USER_PASSWORD "test12"
#define DATABASE_URL "espfirebase-b20ba-default-rtdb.firebaseio.com"
=======
#define THRESHOLD_ACCEL 11 // accelerometer threshold for detecting a fall
#define THRESHOLD_GYRO 11 // gyro threshold for detecting a fall
>>>>>>> acae3554c6ed48b218263d4cd71de18b770b7c94

#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
<<<<<<< HEAD
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
=======
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
>>>>>>> acae3554c6ed48b218263d4cd71de18b770b7c94

MAX30105 particleSensor;
Adafruit_MPU6050 mpu;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;
<<<<<<< HEAD

FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;
=======
>>>>>>> acae3554c6ed48b218263d4cd71de18b770b7c94

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);

<<<<<<< HEAD
  //Heart Rate Monitor - Start
  Setup_Hbeat_Sensor();
  //Heart Rate Monitor - End
  setup_firebase();
=======
  // Setup_Hbeat_Sensor();
  Setup_FallSensor();
>>>>>>> acae3554c6ed48b218263d4cd71de18b770b7c94
}

void loop() {
  // Start Detecting Fall
  Detect_Fall();
}
