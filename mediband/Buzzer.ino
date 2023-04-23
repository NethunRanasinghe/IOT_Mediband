void Siren_Buzz() {
  // Generate a high-pitched siren sound
  Serial.println("Siren Started !");
  for (int i = 2000; i < 5000; i++) {
    tone(buzzerPin, i);
    delay(1);
  }
  
  // Turn off the buzzer
  noTone(buzzerPin);
  
  // Wait for a short time before starting again
  Serial.println("Siren Stopped !");
  delay(1000);
  }
