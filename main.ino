
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLZIejHIF7"
#define BLYNK_DEVICE_NAME "ESP32 blynk temprature 1 input"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define BLYNK_AUTH_TOKEN "LLreBv2Pj7mia766zH1Jg5_VtRSLpGyR"

DHT dht(2, DHT11); //(sensor pin,sensor type)
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

char auth[] = "LLreBv2Pj7mia766zH1Jg5_VtRSLpGyR"; 
char ssid[] = "ROMORA_ITS";
char pass[] = "daffa123"; // Jika tidak menggunakan password kosongkan ""

TaskHandle_t Task1;
TaskHandle_t Task2;


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  lcd.begin();
  pinMode(13,OUTPUT);

  xTaskCreatePinnedToCore(
                    Task1code, 
                    "Task1", 
                    10000,     
                    NULL,       
                    1,        
                    &Task1,    
                    0);       

   xTaskCreatePinnedToCore(
                    Task2code,  
                    "Task2",   
                    10000,     
                    NULL,    
                    1,          
                    &Task2,     
                    1);       
}

void Task1code( void * pvParameters ){
  for(;;){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  bool l = digitalRead(4);
  bool hujan = digitalRead(16);
  
    if (l == 0) {
    lcd.setCursor(9, 1);
    lcd.print("L :");
    lcd.print("High");
    lcd.print(" ");
  } else if (l == 1) {
    lcd.setCursor(9, 1);
    lcd.print("L :");
    lcd.print("Low");
    lcd.print(" ");
  }

    if (hujan == 0) {
    lcd.setCursor(9, 0);
    lcd.print("R :");
    lcd.print("High");
    lcd.print(" ");
    tone(13, 1000, 100);
  } else if (hujan == 1) {
    Blynk.virtualWrite(V3, 0);
    lcd.setCursor(9, 0);
    lcd.print("R :");
    lcd.print("Low");
    lcd.print(" ");
  }

  lcd.setCursor(0, 0);
  lcd.print("T :");
  lcd.print(t);

  lcd.setCursor(0, 1);
  lcd.print("H :");
  lcd.print(h);
  
  }
}

void Task2code( void * pvParameters ){
  
  for(;;){
  float h1 = dht.readHumidity();
  float t1 = dht.readTemperature();
  bool l1 = digitalRead(4);
  bool hujan1 = digitalRead(16);
  
  Blynk.virtualWrite(V0, t1);
  Blynk.virtualWrite(V1, h1);
  
    if (l1 == 0) {
    Blynk.virtualWrite(V2, 1);
    
  } else if (l1 == 1) {
    Blynk.virtualWrite(V2, 0);
    
  }

    if (hujan1 == 0) {
    Blynk.virtualWrite(V3, 1);
    
  } else if (hujan1 == 1) {
    Blynk.virtualWrite(V3, 0);
  }
  
  Serial.println(t1);
  Serial.println(h1);
  Serial.println(l1);
  Serial.println(hujan1);
  
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
