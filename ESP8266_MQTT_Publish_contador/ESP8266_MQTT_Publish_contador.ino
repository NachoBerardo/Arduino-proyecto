//
//  Publicar en un broker MQTT el valor de un contador
//

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"  
#include <WiFiClientSecure.h>
#include <WiFi.h>

// WiFi parameters
#define WLAN_SSID       "Proyecto"
#define WLAN_PASS       "latienedario"

// Adafruit IO
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "inb2005"
#define AIO_KEY       "aio_HBQJ41ZdTKg7XNxMa7VDMEVzazMa"

WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish Contador = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Counter1");



void setup() {
  Serial.begin(115200);
  Serial.println(F("Adafruit IO Example"));

  wifi_connect();
  connect(); // connect to adafruit io
  
}

// Conectarse al WiFi e imprimir la IP
void wifi_connect(){
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  delay(10);
  Serial.print(F("Connecting to "));
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());  
}

// connect to adafruit io via MQTT
void connect() {
  Serial.print(F("Connecting to Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}

void loop() {
  static int cont = 0;
  unsigned long m_actuales = millis();
  static unsigned long m_previos = 0;
  
  // ping adafruit io a few times to make sure we remain connected
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }

  if(m_actuales - m_previos >= 5000){
    m_previos = m_actuales;

    //Publish to Adafruit
    if (! Contador.publish(cont)) {
      Serial.println(F("Failed"));
    }else{cont++;}

  Serial.println(cont);
  }

  //delay(100);
}
