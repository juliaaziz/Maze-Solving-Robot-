#define LeftSensor
#define FrontSensor
#define RightSensor

#define FrontLeftMotor
#define BackLeftMotor
#define FrontRightMotor
#define BackRightMotor

int LeftDistance;
int FrontDistance;
int RightDistance;

void setup() {
  
  pinMode(LeftSensor, INPUT);
  pinMode(FrontSensor, INPUT);
  pinMode(RightSensor, INPUT);

  pinMode(FrontLeftMotor, OUTPUT);
  pinMode(BackLeftMotor, OUTPUT);
  pinMode(FrontRightMotor, OUTPUT);
  pinMode(BackRightMotor, OUTPUT);
  
}

void loop() {
  

  ReadSensors();

  if(FrontDistance > 20){
    Straight();
  }else if(FrontDistance <= 20 && RightDistance <= 20 && LeftDistance > 20){ 
    LeftTurn();
  }else if(FrontDistance <= 20 && LeftDistance <= 20 && RightDistance > 20){
    RightTurn();
  }else if(FrontDistance <= 20 && LeftDistance <= 20 && RightDistance <= 20){
    TurnAround();
  }

}

void ReadSensors() {

  LeftDistance = analogRead(LeftSensor);
  FrontDistance = analogRead(FrontSensor);
  RightDistance = analogRead(RightSensor);
  
}

void Straight(){
  
  digitalWrite(FrontLeftMotor, HIGH);
  digitalWrite(BackLeftMotor, LOW);
  digitalWrite(FrontRightMotor, HIGH);
  digitalWrite(BackRightMotor, LOW);
  delay(4);
  digitalWrite(FrontLeftMotor, LOW);
  digitalWrite(BackLeftMotor, LOW);
  digitalWrite(FrontRightMotor, LOW);
  digitalWrite(BackRightMotor, LOW);
  delay(1);
  
}

void LeftTurn(){

  digitalWrite(FrontLeftMotor, LOW);
  digitalWrite(BackLeftMotor, LOW);
  digitalWrite(FrontRightMotor, HIGH);
  digitalWrite(BackRightMotor, LOW);
  delay(1075);

}

void RightTurn(){

  digitalWrite(FrontLeftMotor, HIGH);
  digitalWrite(BackLeftMotor, LOW);
  digitalWrite(FrontRightMotor, LOW);
  digitalWrite(BackRightMotor, LOW);
  delay(1075);

}

void TurnAround(){

  digitalWrite(FrontLeftMotor, LOW);
  digitalWrite(BackLeftMotor, HIGH);
  digitalWrite(FrontRightMotor, HIGH);
  digitalWrite(BackRightMotor, LOW);
  delay(1075);

}

void Done(){

  digitalWrite(FrontLeftMotor, LOW);
  digitalWrite(BackLeftMotor, LOW);
  digitalWrite(FrontRightMotor, LOW);
  digitalWrite(BackRightMotor, LOW);

}
