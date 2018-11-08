//#define MOTOR1_A 2
//#define MOTOR1_B 3
//#define MOTOR2_A 1
//#define MOTOR2_B 4
//#define MOTOR4_A 0
//#define MOTOR4_B 6
//#define MOTOR3_A 5
//#define MOTOR3_B 7
#define motorKanan1 2
#define motorKanan2 3
#define motorKiri1 0
#define motorKiri2 6
#define trigPin 13
#define echoPin 11
#define line1 A0
#define line2 A1

int count = 0;

void mundur(int output)
{
  motorDC(1, -output);
  motorDC(2, -output);
}

void mundurBelokKiri()
{
  motorDC(1, -255);
  motorDC(2, -45);
}

void majuBelokKiri()
{
  motorDC(1, 255);
  motorDC(2, 45);
}

void maju(int output)
{
  motorDC(1, output);
  motorDC(2, output);
}

void muterKanan(int output)
{
  motorDC(1, -output);
  motorDC(2, output);
}

void muterKiri(int output)
{
  motorDC(1, output);
  motorDC(2, -output);
}

void motorDC(int channel, int output)
{
  if(channel == 1)
  {
    if(output > 0)
    {
      digitalWrite(motorKanan1, LOW);
      digitalWrite(motorKanan2, HIGH);
    }
    else if(output <= 0)
    {
      digitalWrite(motorKanan1, HIGH);
      digitalWrite(motorKanan2, LOW);
      output = -output;
    }
//    analogWrite(motorKanan, output);
  }
  else if(channel == 2)
  {
    if(output > 0)
    {
      digitalWrite(motorKiri1, HIGH);
      digitalWrite(motorKiri2, LOW);
    }
    else if(output <= 0)
    {
      digitalWrite(motorKiri1, LOW);
      digitalWrite(motorKiri2, HIGH);
      output = -output;
    }
//    analogWrite(motorKiri, output);
  }
}

int ultrasonik()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
//  Serial.println(distance);
  return distance;
}

int lineSensor()
{
  return analogRead(line1); 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorKanan1, OUTPUT);
  pinMode(motorKanan2, OUTPUT);
  pinMode(motorKiri1, OUTPUT);
  pinMode(motorKiri2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(line1, INPUT);
  pinMode(line2, INPUT);
//  delay(500);
//  mundurBelokKiri();
//  delay(650);
//  maju(0);
//  delay(2000);
//  majuBelokKiri();
//  delay(650);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(lineSensor());
maju(255);
//  if(lineSensor() <= 20)
//  {
//    mundur(70);
//    delay(800);
//    muterKiri(50);
//    delay(1500);
//  }
//  else
//  {
//    if(ultrasonik() < 60)
//    {
//      maju(100);
//    }
//    else
//    {
//      muterKanan(50);
//      count++;
//      if(count >= 300)
//      {
//        maju(40);
//        count = 0;
//      }
//    }
//  }
}
