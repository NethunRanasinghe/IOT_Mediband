#define buzzerPin D4 // Set the pin for the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  
  Setup_FallSensor();
  Setup_Hbeat_Sensor();
  Setup_Firebase();
}

void loop() {
  // Start Detecting Fall
  Detect_Fall();
}
