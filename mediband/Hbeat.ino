#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;

void Get_Hbeat(){
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;

      Send_Data_To_Firebase(beatAvg);

      if(beatAvg > 100 || beatAvg < 60){
        setFallDetection();
      }

      delay(10000);
    }
  }

  Serial.print(", Avg BPM=");
  Serial.println(beatAvg);

}

void Setup_Hbeat_Sensor(){
  Serial.println("MAX30102 : Initializing...");
  // Initialize sensor
  Wire.begin(D5, D6);
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //I2C port D4 D5, 400kHz speed
  {
    Serial.println("MAX30102 :  was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("MAX30102 : Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  }