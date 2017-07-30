#define LEVER_SWITCH_PIN1 7     //Used 2 limit switches to control basicly.
#define LEVER_SWITCH_PIN2 8
int sensorPin = A0;
int pressSwitch1 = 0;
int pressSwitch2 = 0;
int PWM1 = 3;
int PWM2 = 5;
int LO1 = 2;
int LO2 = 4;
int sensorVal;
int PWMVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(LEVER_SWITCH_PIN1,INPUT);
  pinMode(LEVER_SWITCH_PIN2,INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(LO1, OUTPUT);
  pinMode(LO2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //this code prints sensor value to the console
  pressSwitch1 = digitalRead(LEVER_SWITCH_PIN1);
  pressSwitch2 = digitalRead(LEVER_SWITCH_PIN2);
  
  //Change this value to control speed of the motor, 0 Stops, 255 Full throttle.
  PWMVal = 170;
  
  
  if(pressSwitch1 == HIGH && pressSwitch2 == LOW) //Left Buttun pressed to turn left
  {
  analogWrite(PWM1, PWMVal);
  analogWrite(PWM2, LOW);
  Serial.println("Left Turn.");
  digitalWrite(LO2, HIGH);
  digitalWrite(LO1, LOW);
  }
  else if(pressSwitch1 == LOW && pressSwitch2 == HIGH) //Right Buttun pressed to turn right
  {
  analogWrite(PWM2, PWMVal);
  analogWrite(PWM1, LOW);
  Serial.println("Right Turn.");
  digitalWrite(LO1, HIGH);
  digitalWrite(LO2, LOW);
  }
  else                    //Both buttons released stops the motor
  {
  analogWrite(PWM2, LOW);
  analogWrite(PWM1, LOW);
  Serial.println("Stop.");
  digitalWrite(LO1, LOW);
  digitalWrite(LO2, LOW);
    
  }
  
  //Serial.println(PWMVal);
  delay(250);



}
