#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0, 1); // RX, TX
int led = 9; // the on-board LED
int Data; // the data received
int ws = 4;
int relayb1 = 8;
int relayb2 = 10;
int relayb3 = 11;
int relayb4 = 12;
int buzz = 5;


void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
  pinMode(led,OUTPUT);
  pinMode(ws, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(relayb1, OUTPUT);
  pinMode(relayb2, OUTPUT);
  pinMode(relayb3,OUTPUT);
  pinMode (relayb4, OUTPUT);
  digitalWrite(relayb1, HIGH);
  digitalWrite(relayb2, HIGH);
  digitalWrite(relayb3, HIGH);
  digitalWrite(relayb4, HIGH);
}

void loop() {
  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    if(Data=='1'){  
      digitalWrite(relayb1,LOW);
      Serial.println("Bulb On!");
      Bluetooth.println("Bulb On!");
    }
    else if(Data=='0'){
       digitalWrite(relayb1,HIGH);
       Serial.println("Bulb Off!");
       Bluetooth.println("Bulb Off ! ");
    }
    else if (Data == '2'){
      digitalWrite(relayb2, LOW);
    }
    else if (Data == '3'){
      digitalWrite(relayb2, HIGH);
    }
    else if (Data =='4') {
      digitalWrite(relayb3, LOW);
    }
    else if (Data =='5') {
      digitalWrite(relayb3, HIGH);
    }
    else if (Data =='6') {
      digitalWrite(relayb4, LOW);
    }
    else if (Data =='7') {
      digitalWrite(relayb4, HIGH);
    }
  }
delay(100);
int wval = digitalRead(ws);
if (wval == 1){
  digitalWrite(led, HIGH);
  tone(buzz, 50);
}
else if(wval == 0){
  digitalWrite(led, LOW);
  noTone(buzz);
}
}
