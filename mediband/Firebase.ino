void Send_Data_To_Firebase(){
  
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
        Serial.printf("Set Record... %s\n", Firebase.RTDB.setString(&fbdo, path+"test1", "test5") ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("Set Record... %s\n", Firebase.RTDB.setString(&fbdo, path+"test2", "test6") ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("Set Record... %s\n", Firebase.RTDB.setString(&fbdo, path+"test3", "test7") ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("Set Record... %s\n", Firebase.RTDB.setString(&fbdo, path+"test4", "test8") ? "ok" : fbdo.errorReason().c_str());

}


void setup_firebase(){
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