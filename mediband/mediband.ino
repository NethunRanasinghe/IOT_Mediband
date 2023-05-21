void setup() {
  Serial.begin(115200);

  // Setup Firebase
  Setup_Firebase();

  // Setup heart rate Sensor.
  Setup_Hbeat_Sensor();

  // Setup Fall Detection Sensor(MPU6050), Buzzer and Switch
  Setup_Fall();
}

void loop() {
  // Start Heart Rate Detection
  Get_Hbeat();
  
  // Start Fall Detection
  Detect_Fall();
}