#define WIFI_SSID "Dialog 4G 827"
#define WIFI_PASSWORD "VillAiN248"
#define API_KEY "AIzaSyAWtQRLx_Sovaq0VVuuv980hgz7IPlJ_8E"
#define USER_EMAIL "testuser1@test.com"
#define USER_PASSWORD "test12"
#define DATABASE_URL "espfirebase-b20ba-default-rtdb.firebaseio.com"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const long utcOffsetInSeconds = 19800;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson firebaseJson;

unsigned long dataMillis = 0;

void Setup_Firebase(){
     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to Wi-Fi");
    unsigned long ms = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    timeClient.begin();

    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

    /* Assign the api key (required) */
    config.api_key = API_KEY;

    /* Assign the user sign in credentials */
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;

    /* Assign the RTDB URL */
    config.database_url = DATABASE_URL;

    Firebase.reconnectWiFi(true);
    fbdo.setResponseSize(4096);

    String base_path = "/UsersData/";

    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

    /* Initialize the library with the Firebase authen and config */
    Firebase.begin(&config, &auth);
}

void Send_Data_To_Firebase(String hrate){
  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();

  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  String currentMonthName = months[currentMonth-1];
  int currentYear = ptm->tm_year+1900;

  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay)+ "-" + String(timeClient.getHours())+ "-" + String(timeClient.getMinutes())+ "-" + String(timeClient.getSeconds());
  Serial.print("Current date: ");
  Serial.println(currentDate);

  Serial.println("");

  delay(2000);

  delay(1000);
    // Firebase.ready() should be called repeatedly to handle authentication tasks.

    if (millis() - dataMillis > 5000 && Firebase.ready())
    {
        dataMillis = millis();
        String path = "Devices/";
        path += auth.token.uid.c_str(); //<- user uid of current user that sign in with Emal/Password
        path += "/" + currentDate + "/";
        firebaseJson.set("/heartRate",hrate);
        firebaseJson.set("/spo2", 90);
        firebaseJson.set("/time", currentDate);
        Serial.printf("Set Record... %s\n", Firebase.RTDB.setJSON(&fbdo, path, &firebaseJson) ? "ok" : fbdo.errorReason().c_str());
}
}

void setFallDetection(){
  Serial.printf("Set Record... %s\n", Firebase.RTDB.setInt(&fbdo, path, &firebaseJson) ? "ok" : fbdo.errorReason().c_str());
}
