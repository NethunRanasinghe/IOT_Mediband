#define buzzerPin D4 // Set the pin for the buzzer

void Siren_Buzz() {

  // Generate a high-pitched siren sound
  Serial.println("Buzzer : Siren Started !");
  for (int i = 2000; i < 5000; i++) {
    tone(buzzerPin, i);
    delay(1);
  }
  
  // Turn off the buzzer
  noTone(buzzerPin);
  
  // Wait for a short time before starting again
  delay(1000);
  }

void Buzz_Stop(){
  noTone(buzzerPin);
  Serial.println("Buzzer : Siren Stopped !");
}