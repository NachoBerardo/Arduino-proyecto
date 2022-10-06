  #include "Adafruit_MQTT.h"
  #include "Adafruit_MQTT_Client.h"  
  #include <WiFiClientSecure.h>
  #include <WiFi.h>

  //...........................................VARIABLES PARA WIFI...........................................
  const char* ssid = "Proyecto";
  const char* password = "latienedario";
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;
  
  //...........................................VARIABLES PARA ADAFRUIT...........................................
  #define AIO_SERVER      "io.adafruit.com" 
  #define AIO_SERVERPORT  1883
  #define AIO_USERNAME  "inb2005"
  #define AIO_KEY       "aio_HBQJ41ZdTKg7XNxMa7VDMEVzazMa"

  WiFiClient client;
  
   void initWiFi()
  {
    WiFi.begin(ssid, password);
    Serial.print("connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  //...........................................SET UP ...........................................

  void setup() 
  {
    Serial.begin(115200);
    Serial.println();
    initWiFi();
    
  }

  //...........................................LOOP...........................................
  void loop()
  {
    unsigned long currentMillis = millis();
    if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) 
    {
      Serial.print(millis());
      Serial.println("Reconnecting to WiFi...");
      WiFi.disconnect();
      WiFi.reconnect();
      previousMillis = currentMillis;
    }
  }
