#include <Arduino.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <SocketIoClient.h>

#define LED0 D0
#define LED D1
#define LED2 D2
#define LED3 D3   //
#define LED4 D4

SocketIoClient webSocket;
void onConnect(const char * payload, size_t length) {
  Serial.println("onConnect");
  webSocket.emit("join","\"BeiHang\"");
}
void onMessage(const char * payload, size_t length) {
  // if(strcmp(payload, "open") == 0){
    pinMode(LED2, OUTPUT);
    //digitalWrite(LED3, HIGH);
    pinMode(LED3, OUTPUT);
    delay(500);
    pinMode(LED2, INPUT);
    //digitalWrite(LED3, LOW);
    pinMode(LED3, INPUT);

    Serial.println("onMessage");
  // }
}


void setup() {
  // put your setup code here, to run once:
    //pinMode(LED3, OUTPUT);

      // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    WiFiManager wifiManager;
    //fetches ssid and pass from eeprom and tries to connect
    //and goes into a blocking loop awaiting configuration
    //wifiManager.autoConnect("NodeMCU-Arduino-PlatformIO");
    wifiManager.autoConnect("NodeMCU-Arduino-PlatformIO");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");

    // soket.io client
    webSocket.on("connect", onConnect);
    webSocket.on("message", onMessage);
    webSocket.begin("feiyu.gocoxing.cn");
    //webSocket.begin("192.168.43.28",3001);
    //webSocket.begin("");
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED, LOW);
  //digitalWrite(LED2, LOW);
  // pinMode(LED2, OUTPUT);
  // delay(1000);
  // digitalWrite(LED, HIGH);
  // pinMode(LED2, INPUT);
  // delay(1000);
  webSocket.loop();
}