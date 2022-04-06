#include <Wire.h>
#include <DS3231.h>
#include "max6675.h"
#include "EasyNextionLibrary.h"  // Include EasyNextionLibrary
#define LOOP_TIME 1000
unsigned long timer ;
int starthour;
int startmin;
RTClib myRTC;
EasyNex myNex(Serial1); // Create an object of EasyNex class with the name < myNex >
                       // Set as parameter the Hardware Serial you are going to use
int thermoDO1 = 4;
int thermoCS1= 5;
int thermoCLK1 = 6;
int thermoDO2 = 7;
int thermoCS2= 8;
int thermoCLK2 = 9;
int thermoDO3 = 10;
int thermoCS3= 11;
int thermoCLK3 = 12;
int boiler;
int head;
int cond;
int high =2;
int low =3;
int counttick;
int pushButton = 13;
bool headpriority;
MAX6675 thermocouple1(thermoCLK1, thermoCS1, thermoDO1);
MAX6675 thermocouple2(thermoCLK2, thermoCS2, thermoDO2);
MAX6675 thermocouple3(thermoCLK3, thermoCS3, thermoDO3);
int settempboiler;
int settemphead;
bool startprocess=false;
bool stopprocess=false;
int buzzer =16;
DateTime now;
void setup(){
  myNex.begin(9600); // Begin the object with a baud rate of 9600
                     // If no parameter was given in the begin(), the default baud rate of 9600 will be used
  myNex.writeStr("page page0");
  pinMode(high, OUTPUT);
  pinMode(low,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  pinMode(pushButton, INPUT);
   delay(500);
}

void loop(){
  int buttonState = digitalRead(pushButton);
  if( buttonState == HIGH)
  { headpriority=true;
    
    }
  else
  {
    headpriority=false;
      }
  myNex.NextionListen(); 
  Serial.print("boiler C = "); 
  boiler =thermocouple1.readCelsius();
   Serial.println(boiler);
   Serial.print("head C = "); 
   head = thermocouple2.readCelsius();
   Serial.println(head);
   Serial.print("condenser C = "); 
   cond = thermocouple3.readCelsius();
   Serial.println(cond);
  if ((startprocess == true)&&(stopprocess ==false))
  {Serial.println("in if");
  if((millis() - timer) > LOOP_TIME){
    if((cond >=30)&&(cond<40))
    {digitalWrite(buzzer,HIGH);
    myNex.writeNum("t2.pco", 63488);
    delay(200);
    myNex.writeNum("t2.pco", 65535);
    delay(200);
      }
    if(cond >=40)
     {
      for(int i=counttick;i<=0;i--)
      {digitalWrite(low,HIGH);
      delay(200);
      digitalWrite(low,LOW);
       delay(200);
      counttick--;
        }
      }
    if (headpriority == true)
    {myNex.writeNum("t1.pco", 63488);
    myNex.writeNum("t0.pco", 65535);
      }
    else
    {myNex.writeNum("t1.pco", 65535);
    myNex.writeNum("t0.pco", 63488);
      }
    now = myRTC.now();
    int hour =now.hour();
    int minu =(hour*60 )+ now.minute() ;
    myNex.writeNum("n0.val", (minu-startmin)); 
    myNex.writeNum("boilertemp.val", boiler); 
    myNex.writeNum("headtemp.val", head); 
    myNex.writeNum("condtemp.val", cond); 
    if((boiler<settempboiler)&&(head<settemphead))
    { if(counttick<100){
      digitalWrite(high,HIGH);
      delay(200);
      digitalWrite(high,LOW);
       delay(200);
      counttick++;
      }
    }
    
    if((boiler>settempboiler)&&(head>settemphead))
    { if(counttick>0){
      digitalWrite(low,HIGH);
      delay(200);
      digitalWrite(low,LOW);
       delay(200);
      counttick--;
      }
    }
     if((boiler<settempboiler)&&(head>settemphead)&&(headpriority==true))
    { if(counttick>0){
      digitalWrite(low,HIGH);
      delay(200);
      digitalWrite(low,LOW);
       delay(200);
      counttick--;
      }
    }
     if((boiler>settempboiler)&&(head<settemphead)&&(headpriority==false))
    { if(counttick>0){
      digitalWrite(low,HIGH);
      delay(200);
      digitalWrite(low,LOW);
       delay(200);
      counttick--;
      }
    }
    if((boiler>settempboiler)&&(head<settemphead)&&(headpriority==true))
    { if(counttick<100){
      digitalWrite(high,HIGH);
      delay(200);
      digitalWrite(high,LOW);
       delay(200);
      counttick++;
      }
    }
    if((boiler<settempboiler)&&(head>settemphead)&&(headpriority==false))
    { if(counttick<100){
      digitalWrite(high,HIGH);
      delay(200);
      digitalWrite(high,LOW);
       delay(200);
      counttick++;
      }
    }
    
    timer = millis();
    }
    }
}

void trigger0(){
  startprocess=false;
  stopprocess=false;
  settempboiler = myNex.readNumber("n0.val");
  Serial.print("set boiler = ");
  Serial.println(settempboiler);
  settemphead = myNex.readNumber("n1.val");
  Serial.print("set head = ");
  Serial.println(settemphead);
}

void trigger1(){
               startprocess=true; 
               now = myRTC.now();
               starthour=now.hour();
               startmin=(starthour*60) + now.minute();
                   
               Serial.println("Startprocess = true");// 2nd line: OFF                                                
}
void trigger2(){
               stopprocess=true;             
               Serial.println("Stopprocess = true");// 2nd line: OFF                                                
}
