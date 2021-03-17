#include <SoftwareSerial.h>
char Incoming_value = 0;
SoftwareSerial bluetooth(0,1); //TX RX //QUANDO FOR DAR UPLOAD NO PROGRAMA O BLUETOOTH TEM QUE TÁ FORA DA ENERGIA
char Incoming_value2 = 0;       // liga o tx do modulo no rx da placa


#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequency = 0;

int r=0, g=0, b=0;
int loop_cte ;
int pos1;


#include <Servo.h>

Servo servo1;
Servo servo2;



  

                
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  
 
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
 
  Serial.begin(9600);
 servo1.attach(3);
 servo2.attach(2); // dois é o azul
 
  Serial.println("comeca");
 
 
}         
         


void loop()
{
  if(Serial.available() > 0 )  
  {
    Incoming_value = bluetooth.read();
    Incoming_value2= Serial.read();      
    Serial.print(Incoming_value);
    Serial.print("\t");
    Serial.print(Incoming_value2);    
    Serial.print("\n");
    loop_cte = Incoming_value;
                
  }
 
      while (loop_cte == '1')
      {
        servo1.write(80);
  
  delay(1000);

  servo1.write(20);
  delay(1500);
  
  

//servo1.write(30); // movendo o preto pra analizar 
//delay(500);



  
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
  frequency = pulseIn(sensorOut, LOW);
  
  r=frequency;
  
  Serial.print("\nR= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

//  if (r> 200)
//  {
//    servo2.write(45);
//    servo1.write(90);
//      
////  }
//  else
//  {


  
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  frequency = pulseIn(sensorOut, LOW);

  g=frequency;
  
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

  



  
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  frequency = pulseIn(sensorOut, LOW);
 
  b=frequency;
 
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);


 
  if ((r<230) && (r>200) && (g<130) && (g>100))
  {
    Serial.println("verde");
    servo2.write(105);
    delay(500);
  }

  //verificar cor vermelho
  else if ((r>100) && (r<120) && (g>120))
  {
    Serial.println("vermelho");
    //motor gira até o pote do vermelho
    servo2.write(75);
    delay(500);
  }

  //verificar cor azul
  else if ((r<130) && (r>95) && (g>110) && (g<130))
  {   
    Serial.println("azul");
    //motor gira até o pote do azul
    servo2.write(45);
    delay(500);
  }

  //verificar cor laranja
  else if ((r>70) && (r<90)&& ((g>80)&&(g<130)) )
  { Serial.println("laranja");
    //motor gira até o pote do laranja
    servo2.write(127);
    delay(500);
  }

  //verificar cor marrom
  else if ((r>115)&& (r<160) && (g<170)&& (g>140))
  { Serial.println("marrom");
    //motor gira até o pote amarelo
    servo2.write(153);
    delay(500);
  }

  //verificar cor amarelo
  else if ((r>185)&&(r<250) && (g>195)&&(g<235)) 
  { Serial.println("amarelo");
    //motor gira até o pote marrom
    servo2.write(17);
    delay(500);
  }    

servo1.write(0);
delay(600);
      }}




      
                    
