void setup() {
  // Setup Fall Detection Sensor(MPU6050), Buzzer and Switch
  Setup_Fall();
}

void loop() {
  // Start Fall Detection
  Detect_Fall();
}