bool WheelDirection = 2;  //Z/f pin
int PWM_WheelSpeed = 3;   //Singal pin (0-1023)
int Voltage_WheelSpeed = 5; //VR pin  (0v-5v)

int PotPWM = A0;
int PotVoltage = A1;
int PWM;
int VoltageRange;

bool switchDirection = 4; //Switch for changing the direction
bool switchDirectionStatus;

void setup()
{
  pinMode(WheelDirection, OUTPUT);
  pinMode(PWM_WheelSpeed, OUTPUT);
  pinMode(Voltage_WheelSpeed, OUTPUT);

  pinMode(PotPWM, INPUT);
  pinMode(PotVoltage, INPUT);

  pinMode(switchDirection, INPUT);

  Serial.begin(9600);
}

void loop()
{

  PWM = map(analogRead(PotPWM), 0, 1023, 0, 100); // the speed of PWM would be from (0-100)
  VoltageRange = map(analogRead(PotVoltage), 0, 1023, 0, 5); // the speed of VoltageRange would be from (0v-5v)

  switchDirectionStatus = digitalRead(switchDirection);

  if ( switchDirectionStatus == 0) //Backward
  {
    digitalWrite(WheelDirection, LOW);
    analogWrite(PWM_WheelSpeed, PWM);
    delay(100);
    analogWrite(Voltage_WheelSpeed, VoltageRange);
    delay(1000);
  }

  if ( switchDirectionStatus == 1) //Forward
  {
    digitalWrite(WheelDirection, HIGH);
    analogWrite(PWM_WheelSpeed, PWM);
    delay(100);
    analogWrite(Voltage_WheelSpeed, VoltageRange);
    delay(1000);
  }

}