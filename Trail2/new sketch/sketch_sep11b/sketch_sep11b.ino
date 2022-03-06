#include <max6675.h>
#include <EasyNextionLibrary.h>
#include <trigger.h>
#include <Wire.h>
#include <DS3231.h>
#include "max6675.h"
#include "EasyNextionLibrary.h"
#define LOOP_TIME 500
unsigned long timer ;
int starthour;
int startmin;
RTClib myRTC;
EasyNex myNex(Serial3); // Create an object of EasyNex class with the name < myNex >
                       // Set as parameter the Hardware Serial you are going to use
                       
// SO=Serial Out                       
// CS = chip select CS pin
// SCK = Serial Clock pin                       
int thermoSOPin1 = 4;
int thermoCSPin1 = 5;
int thermoSCKPin1 = 6;

int thermoSOPin2 = 7;
int thermoCSPin2 = 8;
int thermoSCKPin2 = 9;

int thermoSOPin3 = 10;
int thermoCSPin3 = 11;
int thermoSCKPin3 = 12;
==========================
//int thermoDO3 = 10;
//int thermoCS3= 11;
//int thermoCLK3 = 12;
==========================
int boiler;
int head;
int cond;
int high =2;
int low =3;
int counttick;
int pushButton = 13;
bool headpriority;
MAX6675 thermocouple1(thermoSOPin1, thermoCSPin1, thermoSCKPin1);
MAX6675 thermocouple2(thermoSOPin2, thermoCSPin2, thermoSCKPin2);
MAX6675 thermocouple3(thermoSOPin3, thermoCSPin3, thermoSCKPin3);
int settempboiler;
int settemphead;
int settempcond;
bool startprocess=false;
bool stopprocess=false;
int buzzer =16;
DateTime now;
void setup(){
  myNex.begin(9600); // Begin the object with a baud rate of 9600
                     // If no parameter was given in the begin(), the default baud rate of 9600 will be used
  myNex.writeStr("page page0");
  //myNex.writeStr("page page2");
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
   { 
    headpriority=true;
   }
  else
   {
    headpriority=false;
   }
      
  myNex.NextionListen(); 
  boiler = thermocouple1.readCelsius();
  head = thermocouple2.readCelsius();
  cond = thermocouple3.readCelsius();
  
   if(stopprocess ==true)
     {
      for(int i=counttick;i<=0;i--)
       {
       digitalWrite(low,HIGH);
       delay(200);
       digitalWrite(low,LOW);
       delay(200);
       counttick--;
       }
      }
  if ((startprocess == true)&&(stopprocess ==false))
  {
    Serial.println("in if");
    Serial.print("count = ");
    Serial.println(counttick);
    
  if((millis() - timer) > LOOP_TIME)
  {
    Serial.print("boiler C = "); 
    Serial.println(boiler);
    Serial.print("head C = "); 
    Serial.println(head);
    Serial.print("condenser C = "); 
    Serial.println(cond);
    
    if((cond >=30)&&(cond<40))
      {
      digitalWrite(buzzer,HIGH);
      myNex.writeNum("t2.pco", 63488);
      delay(200);
      myNex.writeNum("t2.pco", 65535);
      delay(200);
      }
      
    if(cond >=40)
     {
      for(int i=counttick;i<=0;i--)
        {
        digitalWrite(low,HIGH);
        delay(200);
        digitalWrite(low,LOW);
        delay(200);
        counttick--;
        }
      }
      
    if (headpriority == true)
      {
      myNex.writeNum("t1.pco", 63488);
      myNex.writeNum("t0.pco", 65535);
      }
    else
      {
      myNex.writeNum("t1.pco", 65535);
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
      { 
      if(counttick<100)
        {
        digitalWrite(high,HIGH);
        delay(200);
        digitalWrite(high,LOW);
        delay(200);
        counttick++;
        }
       }
    
    if((boiler>settempboiler)&&(head>settemphead))
      { 
      if(counttick>0)
        {
        digitalWrite(low,HIGH);
        delay(200);
        digitalWrite(low,LOW);
        delay(200);
        counttick--;
        }
      }
      
     if((boiler<settempboiler)&&(head>settemphead)&&(headpriority==true))
     { 
      if(counttick>0)
        {
        digitalWrite(low,HIGH);
        delay(200);
        digitalWrite(low,LOW);
        delay(200);
        counttick--;
        }
     }
     
     if((boiler>settempboiler)&&(head<settemphead)&&(headpriority==false))
     { 
      if(counttick>0)
        {
        digitalWrite(low,HIGH);
        delay(200);
        digitalWrite(low,LOW);
        delay(200);
        counttick--;
        }
      }
      
    if((boiler>settempboiler)&&(head<settemphead)&&(headpriority==true))
    {
      if(counttick<100)
        {
        digitalWrite(high,HIGH);
        delay(200);
        digitalWrite(high,LOW);
        delay(200);
        counttick++;
        }
    }
    
    if((boiler<settempboiler)&&(head>settemphead)&&(headpriority==false))
    { 
      if(counttick<100)
        {
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
  
  //settempboiler = myNex.readNumber("n0.val");
  settempboiler = myNex.readNumber("x0.val", boiler );
  Serial.print("set boiler = ");
  Serial.println(settempboiler);
  
  //settemphead = myNex.readNumber("n1.val");
  settemphead = myNex.readNumber("x1.val", head);
  Serial.print("set head = ");
  Serial.println(settemphead);

  //settempcond = myNex.readNumber("n2.val");
  settempcond = myNex.readNumber("x2.val", cond);
  Serial.print("set condenser = ");
  Serial.println(settempcond);
  
  myNex.writeNum("tm0.en", 1);
}

void trigger1(){
               startprocess=true; 
               startprocess=false; 
               now = myRTC.now();
               starthour=now.hour();
               startmin=(starthour*60) + now.minute();
                   
               Serial.println("Startprocess = true");// 2nd line: OFF                                                
}
void trigger2(){
               stopprocess=true;  
               startprocess=false;            
               Serial.println("Stopprocess = true");// 2nd line: OFF                                                
}
