/* IoT Project - Telegram IoT Gas Leak Detektor*/

#include "CTBot.h"  //Pendeklarasian Library
CTBot myBot;

String ssid = "Veendy-Suseno";      //nama ssid wifi kalian
String pass = "Admin12345";         //password wifi kalian
String token = "XXXX";              //token bot baru kalian
const int id = XXXX;                //id telegram kalian

int buzzer = D2;
int smokeA0 = A0;
int sensorThres = 600;

void setup() {
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");
    myBot.wifiConnect(ssid, pass);
    myBot.setTelegramToken(token);
    if (myBot.testConnection()) {
        Serial.println("Koneksi Bagus");
    } else {
        Serial.println("Koneksi Jelek");
    }
    pinMode(buzzer, OUTPUT);
    pinMode(smokeA0, INPUT);
}

void loop() {
    int analogSensor = analogRead(smokeA0);
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    if (analogSensor > sensorThres){
        tone(buzzer, 1000, 200);
        myBot.sendMessage(id, "Peringatan: Ada Api di Rumah");
    }
    else{
        noTone(buzzer);
    }
    delay(100);
}
