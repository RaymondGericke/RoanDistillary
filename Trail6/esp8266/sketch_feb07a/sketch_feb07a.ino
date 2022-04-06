#include <YAAWS.h>
//=========================================================
//ESP32 WebSocket Server:  thermo111 Temperature/Humidity Sensor
//=========================================================
#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include <max6675.h>
#include "webpage.h"
#include "functions.h"
//-----------------------------------------------
// thermo1  thermo1(27,  thermo111);
int soPin = 3;
int csPin = 4;
int sckPin = 5;
MAX6675 thermo1(sckPin, csPin, soPin);
#define fanLED 2
#define humLED 4
#define SW     8
//-----------------------------------------------
const char* ssid = "LANtern [2Ghz]";
const char* password = "A52E9A7197";
//-----------------------------------------------
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);
//-----------------------------------------------
boolean fanLEDonoff=false; boolean humLEDonoff=false;
String JSONtxt;
//-----------------------------------------------

//====================================================================
void setup()
{
  Serial.begin(9600);
  pinMode(fanLED, OUTPUT); pinMode(humLED, OUTPUT); pinMode(SW, INPUT);
   thermo1.begin();
  //-----------------------------------------------
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("."); delay(500);  
  }
  WiFi.mode(WIFI_STA);
  Serial.print(" Local IP: ");
  Serial.println(WiFi.localIP());
  //-----------------------------------------------
  server.on("/", handleRoot);
  server.begin(); webSocket.begin(); webSocket.onEvent(webSocketEvent);
}
//====================================================================
void loop() 
{
  webSocket.loop(); server.handleClient();
  //-----------------------------------------------
  static unsigned long l = 0;
  unsigned long t = millis();
  if((t-l) > 1000)
  {
    if(fanLEDonoff == false) digitalWrite(fanLED, LOW);
    else digitalWrite(fanLED, HIGH);
    String fanLEDstatus = "OFF";
    if(fanLEDonoff == true) fanLEDstatus = "ON";
    //-----------------------------------------------
    if(humLEDonoff == false) digitalWrite(humLED, LOW);
    else digitalWrite(humLED, HIGH);
    String humLEDstatus = "OFF";
    if(humLEDonoff == true) humLEDstatus = "ON";
    //-----------------------------------------------
    String SWstatus;
    if(digitalRead(SW) == HIGH) SWstatus = "ON";
    else SWstatus = "OFF";
    //-----------------------------------------------
    String TEMPvalString = String( thermo1.readTemperature());
    String HUMvalString = String(int( thermo1.readHumidity()));
    //-----------------------------------------------
    JSONtxt  = "{\"TEMP\":\""+TEMPvalString+"\",";
    JSONtxt += "\"HUM\":\""+HUMvalString+"\",";
    JSONtxt += "\"fanLEDonoff\":\""+fanLEDstatus+"\",";
    JSONtxt += "\"humLEDonoff\":\""+humLEDstatus+"\",";
    JSONtxt += "\"SWonoff\":\""+SWstatus+"\"}";
    webSocket.broadcastTXT(JSONtxt);
  }
}

Header file "functions.h":

//=======================================
//handle function: send webpage to client
//=======================================
void handleRoot()
{
  server.send(200,"text/html", webpageCont);
}
//=====================================================
//function process event: new data received from client
//=====================================================
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t welength)
{
  String payloadString = (const char *)payload;
  //--------------------------------------------------
  if(type == WStype_TEXT)
  {
    byte separator=payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
    String val = payloadString.substring(separator+1);
    //------------------------------------------------
    if(var == "fanLEDonoff")
    {
      fanLEDonoff = false;
      if(val == "ON") fanLEDonoff = true;
    }
    //------------------------------------------------
    if(var == "humLEDonoff")
    {
      humLEDonoff = false;
      if(val == "ON") humLEDonoff = true;
    }
  }
}

Header file "webpage.h":

//=====================
//HTML code for webpage
//=====================
const char webpageCont[] PROGMEM = 
R"=====(
<!DOCTYPE HTML>
<html>
<title>ESP32 WebSocket Server</title>
<!---------------------------CSS-------------------------->
<style>
    #dynRectangle1
    {
        width:0px;
        height:12px;
        top: 9px;
        background-color: rgba(255, 0, 0, 0.863);
        z-index: -1;
        margin-top: 1px;
        border: 3px solid black;
    }
    #dynRectangle2
    {
        width:0px;
        height:12px;
        top: 9px;
        background-color:rgba(0, 0, 255, 0.534);
        z-index: -1;
        margin-top:1px;
        border: 3px solid black;
    }
    body   {background-color:rgba(128,128,128,0.322)}
    h1     {font-size: 40px; color: rgb(156, 5, 5); text-align:center; font-family:calibri}
    h2     {font-size: 25px; color: black; font-family:cursive}
    h3     {font-size: 17px; color:black; font-family:calibri}
    h4     {font-size: 14px; color: black; font-family:Trebuchet MS}
    div.h1 {background-color: whitesmoke;}
    .btn1  
    {
        background-color:#ff3c00b7;
        border: solid 2px rgb(10, 0, 0);
        color: white;
        padding: 4px 16px; 
        font-weight: bold;
        font: 16px arial, sans-serif;
        width: 60px;
        height: 32px;
        line-height: 22px;
        border-radius: 10%;
        opacity: 0.6;
        transition: 0.3s;
        overflow: hidden;
        text-decoration: none;
        cursor: pointer;
    }
    .btn1:hover {opacity: 1}
    .btn2 
    {
        background-color:#002fffa4;
        border: solid 2px rgb(10, 0, 0);
        color: white;
        padding: 4px 16px; 
        font-weight: bold;
        font: 16px arial, sans-serif;
        width: 60px;
        height: 32px;
        line-height: 22px;
        border-radius: 10%;
        opacity: 0.6;
        transition: 0.3s;
        overflow: hidden;
        text-decoration: none;
        cursor: pointer;
    }
    .btn2:hover {opacity: 1}
    span.b1 {float: left; padding: 5px 10px}
    span.b2 {float: left; padding: 5px 10px}
    .msgRect
    {
        float: left;
        text-align: center;
        margin: 21px 50px;
        padding: 10PX 10PX;
        height: 10px;
        width: 180px;
        line-height: 10px;
        background-color:white;
        border: 2px solid black;
    }
</style>
<!--------------------------HTML-------------------------->
<body>
    <h1><div class="h1">ESP32 WebSocket Server</div></h1>
    <h2>
        Temperature: <span style="color:rgb(216, 3, 3)" id="Tempvalue">0</span> C<br>
        Humidity&emsp;&emsp;: <span style="color:rgba(0, 0, 255, 0.795)" id="Humvalue">0</span> % 
    </h2>
    <h3>
        0 C &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
        &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 50 C
        <div id="dynRectangle1"></div><br>
        0 % &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
        &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 100 %
        <div id="dynRectangle2"></div>
    </h3>
    <h4>
        <span class="b1">
            Fan<br>
            <button class="btn1" id="FANbtn" onclick="fanONOFF()"> </button>
        </span>
        <span class="b2">
            Humidifier<br>
            <button class="btn2" id="HUMbtn" onclick="humONOFF()"> </button>
        </span>
        <span class="msgRect" id="msg""> </span>
    </h4>
</body>
<!----------------------JavaScript------------------------>
<script>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':81/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);
       document.getElementById('Tempvalue').innerHTML = JSONobj.TEMP;
       var temp = parseInt(JSONobj.TEMP * 9.5);
       document.getElementById("dynRectangle1").style.width = temp+"px";
       
       document.getElementById('Humvalue').innerHTML = JSONobj.HUM;
       var hum = parseInt(JSONobj.HUM * 4.8);
       document.getElementById("dynRectangle2").style.width = hum+"px";

       document.getElementById('FANbtn').innerHTML = JSONobj.fanLEDonoff;
       document.getElementById('HUMbtn').innerHTML = JSONobj.humLEDonoff;
       
       document.getElementById('msg').innerHTML = JSONobj.SWonoff;
       if(JSONobj.SWonoff == 'ON')
       {
        document.getElementById("msg").innerHTML="WARNING ... switch fan ON";
        document.getElementsByClassName("msgRect")[0].style.backgroundColor="#FFFF33";
       }
       else
       {
        document.getElementById("msg").innerHTML="Server feedback: OK";
        document.getElementsByClassName("msgRect")[0].style.backgroundColor="#00BFFF";
       }
    }
  }
  //----------------------------------------------------
  function fanONOFF()
  {
    FANbtn = 'fanLEDonoff=ON';
    if(document.getElementById('FANbtn').innerHTML == 'ON')
    {
      FANbtn = 'fanLEDonoff=OFF';
    }
    websock.send(FANbtn);
  }
  //----------------------------------------------------
  function humONOFF()
  {
    HUMbtn = 'humLEDonoff=ON';
    if(document.getElementById('HUMbtn').innerHTML == 'ON')
    {
      HUMbtn = 'humLEDonoff=OFF';
    }
    websock.send(HUMbtn);
  }
</script>
</html>
)=====";
