#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "epitech-iot-2019.firebaseio.com"
#define FIREBASE_AUTH "0UQuEnKsocGsErppXqqeEC0UMMeS1bICgWBVWNkm"
#define WIFI_SSID "zezette"
#define WIFI_PASSWORD "kokokiki"

void setup() {
    pinMode(BUILTIN_LED,OUTPUT);
    digitalWrite(BUILTIN_LED,0);
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.setInt("LEDStatus",0);
}

void loop() {
if(Firebase.getInt("LEDStatus"))
{
digitalWrite(BUILTIN_LED,HIGH);
}
else
{
digitalWrite(BUILTIN_LED,LOW);
}
if (Firebase.failed()) // Check for errors {
Serial.print("setting /number failed:");
Serial.println(Firebase.error());
return;
}
