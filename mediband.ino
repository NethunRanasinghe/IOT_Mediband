#define buzzerPin D4 // Set the pin for the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Siren_Buzz();

}
