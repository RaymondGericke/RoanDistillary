#include <ESP8266WiFi.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include "max6675.h"

#define MAX_FRAME_LENGTH 64
#define WIFI_SSID "LANtern [2Ghz]"
#define WIFI_PASS "A52E9A7197"

ESP8266WebServer server(80);
WebSocketsServer ledserver(55533);

const int RED_PIN = D7; bool RED_ON = false;
const int GRE_PIN = D6; bool GRE_ON = false;

/*****************************************/
//MAX66775
const int soPin = 3;
const int csPin = 4;
const int sckPin = 5;
MAX6675 thermo1(sckPin, csPin, soPin);

unsigned long t_prev;
float degC;
int toggleT1 = 0;
/*****************************************/

void handleRoot() {
  String page = 
    "<html>"
      "<head><title>LED</title></head>"
      "<body>"
        "<button style='width:200px; height:100px; background-color:red;'   onclick='bclick(\"0\")' id='redled'>LED 1</button>"
        "<button style='width:200px; height:100px; background-color:green;' onclick='bclick(\"1\")' id='greenled'>LED 2</button>"
        "<h1 id='redstatus' style='width:200px; height:100px; '>Status: Unknown</h1>"
        "<h1 id='grestatus' style='width:200px; height:100px; '>Status: Unknown</h1>"

        "<script>"
        // Open connection
        "const ws = new WebSocket(\"ws://" + WiFi.localIP().toString() + ":55533\");"

         // Server messages
            "ws.addEventListener('message', function (e) {"
              "console.log(e.data);"
              "if (e.data == \"redoff\") { document.getElementById('redstatus').innerHTML = 'Red: OFF' ; }"
              "if (e.data == \"redon\") { document.getElementById('redstatus').innerHTML = 'Red: ON' ; }"
              "if (e.data == \"greoff\") { document.getElementById('grestatus').innerHTML = 'Green: OFF' ; }"
              "if (e.data == \"greon\") { document.getElementById('grestatus').innerHTML = 'Green: ON' ; }"
            "});"

            // Errors
            "ws.addEventListener('error', function (e) {"
              "console.log(e);"
            "});"
              
          "function bclick(n) {"
              // Send data
              "if (n == '0') ws.send(\"togglered\");"
              "if (n == '1') ws.send(\"togglegreen\");"  
          "}"
        "</script>"
      "</body>"
    "</html>"
  ;

  server.send(200, "text/html", page.c_str());
}
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send( 404, "text/plain", message);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t lenght) {
  switch (type) {
    case WStype_DISCONNECTED: break;
    case WStype_CONNECTED: break;
    case WStype_TEXT: {
      String data = String((char*)payload);
      Serial.println("Client said: " + data);
      if (data == "togglered") {
        RED_ON = !RED_ON; //Serial.println(RED_ON ? "RED LED: ON" : "RED LED: OFF");

        digitalWrite(RED_PIN, RED_ON ? HIGH : LOW);

        char status[32];
        sprintf(status, "red%s", RED_ON ? "on" : "off");
        ledserver.sendTXT(num, status);
      } else if (data == "togglegreen") {
        GRE_ON = !GRE_ON; //Serial.println(GRE_ON ? "GREEN LED: ON" : "GREEN LED: OFF");

        digitalWrite(GRE_PIN, GRE_ON ? HIGH : LOW);

        char status[32];
        sprintf(status, "gre%s", GRE_ON ? "on" : "off");
        ledserver.sendTXT(num, status);
      }
     
      break;
    }
  }
}

void initWIFI() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println(WiFi.localIP());
}
void initHTTPServer() {
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
void initLEDServer() {
  pinMode(RED_PIN, OUTPUT); digitalWrite(RED_PIN, LOW);
  pinMode(GRE_PIN, OUTPUT); digitalWrite(GRE_PIN, LOW);

  ledserver.begin();
  ledserver.onEvent(webSocketEvent);
}

void setup() {
  Serial.begin(115200); Serial.println("");
  initWIFI();
  initHTTPServer();
  initLEDServer();

}
void loop() {
  ledserver.loop();
  server.handleClient();
  
}
