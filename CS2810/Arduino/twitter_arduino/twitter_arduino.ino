// Generate a peaceful glow until someone on twitter mentions you.
/*
 sButton One: Sends a message to Twitter.
 The Light:  Glow peacefully until commanded by Twitter to change.
 Button Two: Hold until WHITE LIGHT; Resets LED to steadyGlow.
 
 steadyGlow() - the default state of the light
 mention() - someone has mentioned @yourUserName "stujeffarduino"
 buttonSend() - update Twitter status
 buttonReset() - return to steadyGlow()
 
*/

const int rButton = 10; // reset button 
int reset_btn_val = 0;
const int sButton = 11; // send button
int send_btn_val = 0;
String state = "steadyGlow";

int ledAnalogOne[] = {3, 5, 6}; // PWM RGB LED pins
// Analog LED 3 = redPin, 5 = greenPin, 6 = bluePin

// Defined Colors 
const byte BLACK[] = {0, 0, 0};        
const byte WHITE[] = {255, 255, 255};  
const byte RED[] = {255, 0, 0};       
const byte GREEN[] = {0, 255, 0};     
const byte BLUE[] = {0, 0, 255};       
const byte ORANGE[] = {83, 4, 0};      
const byte YELLOW[] = {255, 255, 0};   
const byte MAGENTA[] = {255, 0, 255};  

void setup(){  
  Serial.begin(9600);
  pinMode(rButton, INPUT);
  pinMode(sButton, INPUT);
  for(int i = 0; i < 3; i++){     // set the 3 LED pins as outputs
    pinMode(ledAnalogOne[i], OUTPUT); 
  }
}

void loop(){  
  listenToSerial();
  buttonSend();
  buttonReset();
  setState(state);
}
void setState(String s){
  if (s == "steadyGlow") steadyGlow();
  if (s == "mention") mention();
}
void listenToSerial(){ // Twitter commands enter here
  int serialMsg = 0;
  if (Serial.available()){
    serialMsg = Serial.read();
    //if (serialMsg == 1) state = "mention"; // processing
    if (serialMsg == 49) state = "mention"; // python twitter4j API not importing??
  }
}
void buttonSend(){  // Twitter posts sent here
  send_btn_val = digitalRead(sButton);
  if (send_btn_val == HIGH){
    Serial.print("#steadyGlowTest");
    delay(200);
    sent();
  }
}
void buttonReset(){
  reset_btn_val = digitalRead(rButton);
  if (reset_btn_val == HIGH){
    state = "steadyGlow";
  }
}
void steadyGlow(){
  state = "steadyGlow";
  if (state == "steadyGlow") {
    fadeToColor(ledAnalogOne, RED, BLUE, 6);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  if (state == "steadyGlow") {
    fadeToColor(ledAnalogOne, BLUE, GREEN, 6);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  if (state == "steadyGlow") {
    fadeToColor(ledAnalogOne, GREEN, YELLOW, 6);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  if (state == "steadyGlow") {
    fadeToColor(ledAnalogOne, YELLOW, ORANGE, 6);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  if (state == "steadyGlow") {
    fadeToColor(ledAnalogOne, ORANGE, RED, 6);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
}
void mention(){
  state = "mention";
  if (state == "mention"){
    fadeToColor(ledAnalogOne, RED, BLACK, 1);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  buttonReset();
  if (state == "mention"){
    fadeToColor(ledAnalogOne, BLACK, RED, 0);
  } else {
    setState(state);
  }
  listenToSerial();
  buttonSend();
  buttonReset();
}
void sent(){
  setColor(ledAnalogOne, WHITE);
  delay(500);
}
// Color stuff

void setColor(int* led, byte* color){
  for(int i = 0; i < 3; i++){            
    analogWrite(led[i], 255 - color[i]); 
  }
}

void setColor(int* led, const byte* color){
  byte tempByte[] = {
    color[0], color[1], color[2]};
  setColor(led, tempByte);
}

void fadeToColor(int* led, byte* startColor, byte* endColor, int fadeSpeed){
  int changeRed = endColor[0] - startColor[0];
  int changeGreen = endColor[1] - startColor[1]; 
  int changeBlue = endColor[2] - startColor[2]; 
  int steps = max(abs(changeRed),max(abs(changeGreen), abs(changeBlue))); 

  for(int i = 0 ; i < steps; i++){ 
    byte newRed = startColor[0] + (i * changeRed / steps); 
    byte newGreen = startColor[1] + (i * changeGreen / steps); 
    byte newBlue = startColor[2] + (i * changeBlue / steps); 
    byte newColor[] = {newRed, newGreen, newBlue}; 
    setColor(led, newColor); 
    delay(fadeSpeed); 
  }
  setColor(led, endColor);
}

void fadeToColor(int* led, const byte* startColor, const byte* endColor, int fadeSpeed){
  byte tempByte1[] = {startColor[0], startColor[1], startColor[2]};
  byte tempByte2[] = {endColor[0], endColor[1], endColor[2]};
  fadeToColor(led, tempByte1, tempByte2, fadeSpeed);
}




