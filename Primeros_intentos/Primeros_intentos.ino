    //...........................................DEFINO LIBRERIAS...........................................
  #include <WiFi.h>
  #include <PubSubClient.h>
  #include <WiFiClientSecure.h>
  #include <time.h>
    //...........................................VARIABLES PARA EL BROKER...........................................

  WiFiClient papa;
  PubSubClient mqttClient(papa); 
  char *mqttServer = "8c50c13b35c240f18787982560b1eee7.s1.eu.hivemq.cloud";
  int mqttPort = 8883;
  char *mqtt_username = "inb2005";
  char *mqtt_password = "Spotlight";

  //...........................................VARIABLES PARA WIFI...........................................
  const char* ssid = "Proyecto";
  const char* password = "latienedario";
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;
  
//...........................................FUNCION RECONECTAR SERVER...........................................
//  void callback(char* topic, byte* payload, unsigned int length) {
//    Serial.print("Callback - ");
//    Serial.print("Message:");
//    for (int i = 0; i < length; i++) 
//    {
//      Serial.print((char)payload[i]);
//    }
//  }
  
  //...........................................SET UP DEL SERVIDOR...........................................
  void setupMQTT() {
    mqttClient.setServer(mqttServer, mqttPort);
    if (mqttClient.connected())
    {
      Serial.println("Connected");
    }
    // set the callback function
   //mqttClient.setCallback(callback);
  }

  


  //...........................................FUNCION RECONECTAR BROKER...........................................
//  void reconnecting() {
//    Serial.println("Connecting to MQTT Broker...");
//    while (!mqttClient.connected()) 
//    {
//      Serial.println("Reconnecting to MQTT Broker..");
//      String clientId = "ESP32Client-";
//      clientId += String(random(0xffff), HEX);
//      
//      if (mqttClient.connect(clientId.c_str(), mqtt_username, mqtt_password)) 
//      {
//        Serial.println("Connected.");
//        // subscribe to topic
//        mqttClient.subscribe("esp32/message");
//      }
//
//      else 
//      {
//        Serial.print("failed, rc=");
//        Serial.print(mqttClient.state());
//        Serial.println(" try again in 5 seconds");
//        delay(5000);
//      }
//      
//    }
//  }


      //...........................................FUNCION CONECTAR WIFI...........................................
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
    Serial.begin(9600);
    Serial.println();
    initWiFi();
    setupMQTT();
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
  
    if (mqttClient.connected())
    {
      Serial.print("Conectado a HiveMQ");
    }
    //mqttClient.loop();
  }

 
