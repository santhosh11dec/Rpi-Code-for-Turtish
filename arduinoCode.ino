int IC1_enableA = 3; //pin number of Enable first motor
int IC1_ForwardA = 2; //pin number of Forward 1st motor
int IC1_BackwardA = 4; //pin number of Backward 1st motor

int IC1_enableB = 6; //pin number of Enable second motor
int IC1_ForwardB= 7; //pin number of Backward 1st motor
int IC1_BackwardB = 8;//pin number of Backward 1st motor

int IC2_enableA= 9;//pin number of Enable second motor
int IC2_ForwardA = 10;
int IC2_BackwardA = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(IC1_enableA,OUTPUT);
  pinMode(IC1_ForwardA,OUTPUT);
  pinMode(IC1_BackwardA,OUTPUT);

  pinMode(IC1_enableB,OUTPUT);
  pinMode(IC1_ForwardB,OUTPUT);
  pinMode(IC1_BackwardB,OUTPUT);

  pinMode(IC2_enableA,OUTPUT)  ;
  pinMode(IC2_ForwardA,OUTPUT);
  pinMode(IC2_BackwardA,OUTPUT);

}

void MotorDrive(int time,char pin,int Speed)  
{
  if(Speed >=0)
  {
    digitalWrite(IC2_ForwardA, HIGH); 
    digitalWrite(IC2_BackwardA, LOW);
    analogWrite(pin, Speed); //Analog write values should be within 0 and 255 - 0 to 100 duty cycle
    delay(time); //time in milliseconds
  }
  else
  {
    digitalWrite(IC2_ForwardA, LOW); 
    digitalWrite(IC2_BackwardA, HIGH);
    analogWrite(pin, Speed) ;//Analog write values should be within 0 and 255 - 0 to 100 duty cycle
    delay(time);
  }
}

float iteration = 0;
float sinWave = 0;

void loop() {
  // put your main code here, to run repeatedly:
  sinWave = sin(1.5*iteration);
  MotorDrive(100,IC1_enableA,5*(sinWave));
  iteration = iteration+0.1;
  
  if (Serial.available())  
  {
     if((Serial.read() - '0') == 0) // convert the character '1'-'9' to decimal 1-9
     {
       exit(0);
     }  
  }
}
