  //...........................................DEFINO LIBRERIAS...........................................\\
  #include <WiFi.h>
  #include <PubSubClient.h>
  #include <WiFiClientSecure.h>
  #include <time.h>
  
  //...........................................VARIABLES PARA EL BROKER...........................................\\
  //WiFiClient wifiClient;
  //PubSubClient client(wifiClient); 
  char *mqttServer = "79267f99bb244d74894f7be09778e576.s1.eu.hivemq.cloud";
  int mqttPort = 883;
  char mqtt_username = "inb2005";
  char mqtt_password = "nacho2005";

  //...........................................VARIABLES PARA WIFI...........................................\\
  const char* ssid = "IoT";
  const char* password = "mandalegas";
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;

  //...........................................SET UP DEL SERVIDOR...........................................\\
  void setupMQTT() 
  {
    mqttClient.setServer(mqttServer, mqttPort);
    // set the callback function
    mqttClient.setCallback(callback);
  }

  //...........................................FUNCION RECONECTAR SERVER...........................................\\
  void callback(char* topic, byte* payload, unsigned int length) 
  {
    Serial.print("Callback - ");
    Serial.print("Message:");
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
  }


  //...........................................FUNCION RECONECTAR BROKER...........................................\\
  void reconnect() 
  {
    Serial.println("Connecting to MQTT Broker...");
    while (!mqttClient.connected()) 
    {
      Serial.println("Reconnecting to MQTT Broker..");
      String clientId = "ESP32Client-";
      clientId += String(random(0xffff), HEX);
      
      if (mqttClient.connect(clientId.c_str(), mqtt_username, mqtt_passwor)) 
      {
        Serial.println("Connected.");
        // subscribe to topic
        mqttClient.subscribe("esp32/message");
      }

      else 
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds"); // Wait 5 seconds before retrying
        delay(5000);
      }
      
    }
  }


      //...........................................FUNCION CONECTAR WIFI...........................................\\
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

 }
 
  //...........................................SET UP ...........................................\\

  void setup() 
  {
    Serial.begin(9600);
    Serial.println();
    initWiFi();
    setupMQTT();
  }

  //...........................................LOOP...........................................\\
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
  
    if (!mqttClient.connected())
    {
      reconnect();
    }
    mqttClient.loop();
  }

 
