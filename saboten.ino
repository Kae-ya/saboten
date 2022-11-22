#include <Wire.h>
#include "rgb_lcd.h"
#include <DHT.h> 
#include <Servo.h>      // Servoライブラリの読み込み
 
Servo myservo1;
Servo myservo2;
rgb_lcd lcd;
#define DHT_PIN 4             // DHT11のDATAピンをデジタルピン7に定義
#define DHT_MODEL DHT11
DHT dht(DHT_PIN, DHT_MODEL);
int light_sensor = A3;
int count = 0;


void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);
  dht.begin();
  myservo1.attach(6, 500, 2400);  // サーボの割当(パルス幅500~2400msに指定)
  myservo2.attach(5, 500, 2400);
  pinMode(9,OUTPUT);
} 

void loop() {
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  int raw_light = analogRead(light_sensor);
  int water = analogRead(A2);
  int water_heght = analogRead(A0);
  int light = map(raw_light, 0, 1023, 0, 100);
  if (isnan(Humidity) || isnan(Temperature)) {  // 読み取りのチェック
     Serial.println("ERROR");
     return;
  }
  Serial.print("明るさ:");
  Serial.println(light);
  Serial.print("温度:");
  Serial.print(Temperature);
  Serial.print("[℃]");
 
  Serial.print("湿度:"); 
  Serial.print(Humidity);  
  Serial.println("[%]");
  Serial.print("湿り気:");
  Serial.println(water);
  Serial.print("水の残り:");
  Serial.println(water_heght);
  Serial.println(" ");
  
  
  if(light < 60){
    lcd.setCursor(0, 0);
    lcd.print("\xb8\xd7\xb8\xc8?");
    count += 1;
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("     ");
  }
  
  if(Temperature > 20){
    lcd.setCursor(5, 0);
    lcd.print("\xb1\xc2\xb8\xc8?");
    count += 1;
  }
  else{
    lcd.setCursor(5, 0);
    lcd.print("     ");
  }
  
  if(Humidity > 25){
    lcd.setCursor(0, 1);
    lcd.print("\xbc\xde\xd2\xbc\xde\xd2\xbc\xd4\xdd?");
    count += 1;
  }
  else{
    lcd.setCursor(0, 1);
    lcd.print("          ");
  }
  if(water_heght < 50){
    lcd.setCursor(10, 0);
    lcd.print("\xd0\xbd\xde\xc5\xb2\xd6");
  }
  else{
    lcd.setCursor(10, 0);
    lcd.print("      ");
  }

  if(water > 700){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }

  if(count > 1){
    myservo1.write(95);
    myservo2.write(90);
  }
  else{
    myservo1.write(0);
    myservo2.write(0);
  }
  //Serial.println(count);
  count = 0;
  delay(1000);
}
