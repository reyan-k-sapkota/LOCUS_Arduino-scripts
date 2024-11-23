#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "P0Ud70rqLBJSv4ufXlmxsCFY1Pytec2Y";

char ssid[] = "Your_Wifi";
char pass[] = "Your_Wifi_Password";
int wt=A0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(wt, INPUT);


  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  int val = analogRead(wt);
  Serial.println(val);
  delay(200);
  if(val >550){
    Blynk.notify("Your house is about to catch a fire! Call a firebrigade ASAP!");
    delay(100);
    Blynk.email("sapkotarex29@gmail.com" , "Gas Detected!", "Call 911 ASAP!");
    delay(100);
   
    
    
  }
}
