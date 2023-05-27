#include <DFRobot_BMI160.h>

#define buttonPin D3  // Set the pin for the button

int buttonState = 0;  // Flag to track button state

DFRobot_BMI160 bmi160;
const int8_t i2c_addr = 0x69;

void Setup_Fall() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
  Wire.begin(D1,D2);
  //init the hardware bmin160
  if (bmi160.softReset() != BMI160_OK) {
    Serial.println("MPU6050 : reset false");
    while (1)
      ;
  }

  //set and init the bmi160 i2c address
  if (bmi160.I2cInit(i2c_addr) != BMI160_OK) {
    Serial.println("MPU6050 : init false");
    while (1);
  }
}

void Detect_Fall() {
  float accMagnitude = 0;
  float angVelMagnitude = 0;

  buttonState = digitalRead(buttonPin);

  int i = 0;
  int rslt;
  int16_t accelGyro[6] = { 0 };

  const float ACC_THRESHOLD = 2.5;     // Acceleration threshold for fall detection
  const float ANG_VEL_THRESHOLD = 110;  // Angular velocity threshold for fall detection

  //get both accel and gyro data from bmi160
  //parameter accelGyro is the pointer to store the data
  rslt = bmi160.getAccelGyroData(accelGyro);
  if (rslt == 0) {

    double GyroX = accelGyro[0] * 3.14 / 180.0;
    double GyroY = accelGyro[1] * 3.14 / 180.0;
    double GyroZ = accelGyro[2] * 3.14 / 180.0;

    double AccelX = accelGyro[3] / 16384.0;
    double AccelY = accelGyro[4] / 16384.0;
    double AccelZ = accelGyro[5] / 16384.0;

    accMagnitude = sqrt(sq(AccelX + AccelY + AccelZ));

    // Calculate angular velocity magnitude
    angVelMagnitude = sqrt(sq(GyroX + GyroY + GyroZ));

    // Check for fall condition
    if (accMagnitude > ACC_THRESHOLD && angVelMagnitude > ANG_VEL_THRESHOLD) {
      Serial.println("MPU6050 : State Abnormal : Fall detected !");
      while (true) {
        buttonState = digitalRead(buttonPin);
        Serial.println(buttonState);
        setFallDetection();
        Siren_Buzz();
        if (buttonState == LOW) { 
          Serial.println("MPU6050 : Buzzer Stopped !"); // Check if button is pressed
          Buzz_Stop();
          break;
        }
      }
    } else {
      // Buzz_Stop();
      Serial.println("MPU6050 : State : Normal !");
    }
  }
}