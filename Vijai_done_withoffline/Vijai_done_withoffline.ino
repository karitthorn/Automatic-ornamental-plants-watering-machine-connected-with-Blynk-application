#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define ON LOW
#define OFF HIGH


char auth[] = "cPs4vXujt7N9kL2SKXFJLiwCdf07oOuH";
char ssid[] = "";
char pass[] = "";

void setup()
{

  Serial.begin(115200);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(0, OUTPUT);
  Blynk.begin(auth, "Wiroj", "0863499702");

}

BLYNK_WRITE(V1)
{
  digitalWrite(5, 1);
  delay(10000);
  digitalWrite(5, 0);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  analogRead(A0);
}

void loop() {
  digitalWrite(16, 1);
  Blynk.run();
  if ( ! Blynk.connected() ) {
    Serial.print(" I can't Connected");
    digitalWrite(16, 0);

    delay(720000);

    digitalWrite(5, 1);
    delay(10000);
    digitalWrite(5, 0);
    digitalWrite(0, 1);

    delay(720000);

    digitalWrite(0, 0);
    digitalWrite(5, 1);
    delay(10000);
    digitalWrite(5, 0);
  } else {
    Serial.print("  Connected  ");
    int bm = analogRead(A0);
    digitalWrite(16, 1);
    bm = bm * 100;
    bm = bm / 800;
    bm = 100 - bm;
    Blynk.virtualWrite(V2, bm);
    if(bm < 30 && bm > 1){
  digitalWrite(5, 1);
  delay(10000);
  digitalWrite(5, 0);
      }

  }




}
