#include <WiFi.h>
  #include <PubSubClient.h>
  #include <WiFiClientSecure.h>
  #include <time.h>

  //...........................................VARIABLES PARA WIFI...........................................
  const char* ssid = "Proyecto";
  const char* password = "latienedario";
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;

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
