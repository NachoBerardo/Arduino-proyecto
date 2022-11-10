
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

//#define WLAN_SSID       "Fibertel WiFi 112 2.4Ghz"
//#define WLAN_PASS       "nacho260705"
#define WLAN_SSID       "Proyecto"
#define WLAN_PASS       "latienedario"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com" //"52.54.110.50"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "inb2005"
#define AIO_KEY       "aio_gQQk42g7FtmZs4uaAoySrtqF08DB"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

int CantidadAutos1 = 0;
int CantidadAutos2 = 0;
int AutosTotales;

//SEMAFORO 2
#define V1  14 //D5
#define A1  12 //D6
#define R1  13 //D7

// SEMAFORO 1
#define V2  5 //D1
#define A2  4 //D8
#define R2  2 //D4

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'salidaDigital' for subscribing to changes to the button
Adafruit_MQTT_Subscribe FeedSemaforo1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/autos", MQTT_QOS_1);
Adafruit_MQTT_Subscribe FeedSemaforo2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/autos2", MQTT_QOS_1);

/*************************** Sketch Code ************************************/
void Semaforo1callback(char *data, uint16_t len) {
  Serial.print("Semaforo 1: ");
  Serial.println(data);
  CantidadAutos1 = atoi((char *)FeedSemaforo1.lastread);
  Serial.println(CantidadAutos1);
}

void Semaforo2callback(char *data, uint16_t len) {
  Serial.print("Semaforo 2: ");
  Serial.println(data);
  CantidadAutos2 = atoi((char *)FeedSemaforo2.lastread);
  Serial.println(CantidadAutos2);
  
}
//
//void Semaforocallback(char *data, uint16_t len) {
//  Adafruit_MQTT_Subscribe *subscription;
//  subscription = mqtt.readSubscription(5000);
//  Serial.println("AAA");
//  if (subscription == &FeedSemaforo1) {
//  Serial.print("Semaforo 1: ");
//  Serial.println(data);
//  CantidadAutos1 = atoi((char *)FeedSemaforo2.lastread);
//  Serial.println(CantidadAutos1);
//  
//  }
//}

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

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(F("Adafruit MQTT demo"));
  wifi_connect();
  FeedSemaforo1.setCallback(Semaforo1callback);
  FeedSemaforo2.setCallback(Semaforo2callback);
  mqtt.subscribe(&FeedSemaforo1);
  mqtt.subscribe(&FeedSemaforo2);
  pinMode(V1, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() {
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }

  CantidadAutos1 = atoi((char *)FeedSemaforo1.lastread);
  CantidadAutos2 = atoi((char *)FeedSemaforo2.lastread);
  AutosTotales = CantidadAutos1 - CantidadAutos2;
  Serial.println(AutosTotales);

  if (AutosTotales >= -2 && AutosTotales <= 2)
  {
    Serial.println("Caso 1");
    Serial.println("Caso normal");
    digitalWrite(R1, HIGH);
    digitalWrite(V2, HIGH);
    delay(28000);
    digitalWrite(R1, LOW);
    digitalWrite(V2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(V1, HIGH);
    digitalWrite(R2, HIGH);
    delay(28000);
    digitalWrite(V1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  // POCO FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > 2 && AutosTotales <= 5)
  {
    Serial.println("POCO FAVORABLE PARA SEMAFORO 2");
    Serial.println("Caso 2");
    digitalWrite(R1, HIGH);
    digitalWrite(V2, HIGH);
    delay(34000);
    digitalWrite(R1, LOW);
    digitalWrite(V2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(V1, HIGH);
    digitalWrite(R2, HIGH);
    delay(22000);
    digitalWrite(V1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  // MUY POCO FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales > 5)
  {
    Serial.println("MUY POCO FAVORABLE PARA SEMAFORO 2");
    Serial.println("Caso 3");
    digitalWrite(R1, HIGH);
    digitalWrite(V2, HIGH);
    delay(42000);
    digitalWrite(R1, LOW);
    digitalWrite(V2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(V1, HIGH);
    digitalWrite(R2, HIGH);
    delay(14000);
    digitalWrite(R2, LOW);
    digitalWrite(V1, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  // FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales >= -5 && AutosTotales < -2)
  {
    Serial.println("FAVORABLE PARA SEMAFORO 2");
    Serial.println("Caso 4");
    digitalWrite(R1, HIGH);
    digitalWrite(V2, HIGH);
    delay(22000);
    digitalWrite(R1, LOW);
    digitalWrite(V2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(V1, HIGH);
    digitalWrite(R2, HIGH);
    delay(34000);
    digitalWrite(V1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  //MUY FAVORABLE PARA SEMAFORO 2
  else if (AutosTotales < -5)
  {
    Serial.println("MUY FAVORABLE PARA SEMAFORO 2");
    Serial.println("Caso 5");
    digitalWrite(R1, HIGH);
    digitalWrite(V2, HIGH);
    delay(14000);
    digitalWrite(R1, LOW);
    digitalWrite(V2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(V1, HIGH);
    digitalWrite(R2, HIGH);
    delay(42000);
    digitalWrite(V1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(4000);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW );
  }

}
