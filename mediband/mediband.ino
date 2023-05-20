#define buzzerPin D4 // Set the pin for the buzzer
#define pushbtn D7 // Set the pin for the push button

int gswitchState = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushbtn, INPUT);

  Serial.begin(115200);
  
  //Setup_FallSensor();
  Setup_Firebase();
  //Setup_Hbeat_Sensor();
}

void loop() {
  gswitchState = digitalRead(pushbtn);
  int hbeatnew = random(65,74);
  Get_State();
  //Detect_Fall();
  //Get_Hbeat();

  Send_Data_To_Firebase(hbeatnew);
}

int Get_State(){
  return gswitchState;
}