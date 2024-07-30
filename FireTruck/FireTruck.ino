#define FLAMERIGHT 2
#define FLAMECENTER 3 
#define FLAMELEFT 4
#define MQ2 12

#define M1  7
#define M2  8
#define M3  5
#define M4  6
#define Pump 13

void move_forward(){
  digitalWrite(M1,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M4,LOW);
}
void move_Right(){
  digitalWrite(M1,LOW);
  digitalWrite(M3,HIGH);
  digitalWrite(M2,HIGH);
  digitalWrite(M4,LOW);
}
void move_Left(){
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  digitalWrite(M1,HIGH);
  digitalWrite(M3,LOW);
}
void move_Stop(){
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  digitalWrite(M1,LOW);
  digitalWrite(M3,LOW);
}
void fire_off(){
digitalWrite(Pump,HIGH);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(FLAMERIGHT,INPUT);
  pinMode(FLAMECENTER,INPUT);
  pinMode(FLAMELEFT,INPUT);
  pinMode(MQ2,INPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  pinMode(Pump,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  int righ = digitalRead(FLAMERIGHT);
  int left = digitalRead(FLAMELEFT);
  int center = digitalRead(FLAMECENTER);
  if((righ == HIGH && center == HIGH && left == HIGH) || (righ == LOW && center == LOW && left == LOW)){
    move_Stop();
   
    
  }
  else if(righ == LOW && center == HIGH && left == HIGH){
    move_Right();
  }
  else if(left == LOW && righ == HIGH && center == HIGH){
    move_Left();
  }
  else if (center == LOW){
    move_forward();
  }
}
