#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

//#define wifi_ssid "123"
//#define wifi_password "11111111"

//#define mqtt_server "192.168.43.228"

#define wifi_ssid "456"
#define wifi_password "22222222"

//#define mqtt_server "192.168.43.237"
#define mqtt_server "192.168.43.131"

char data[16];
float newTemp = 1;
long lastMsg = 0;
float temp = 0.0;
char start = 'S';
char packet = 'A';
int countDelay=0;
uint8_t commandCode;
char lastCommandCode;
String stringCommandCode;
char prevLastCommandCode;
char bufferNode[4];
char ballX;
char ballY;

void callback(char* topic, byte* payload, unsigned int length) {
//  Serial.print("Message arrived [");
//  Serial.print(topic);
//  Serial.print("] ");
//  for (int i=0;i<length;i++) {
//    Serial.print((char)payload[i]);
//    start = (char)payload[i];
//  }
  if(strcmp(topic,"robot1") == 0 || strcmp(topic,"lama") == 0)
  {
    start = (char)payload[0];
  }
  if(strcmp(topic,"ballXLama") == 0)
  {
    ballX = (char)payload[0];
  }
}


WiFiClient espClient;
PubSubClient client(espClient);
char message_buff[100];



void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);
  

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
//    Serial.print(".");
  }

//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
//    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
  
    if (client.connect("clientLama")) {
//      Serial.println("connected");
    } else {
//      Serial.print("failed, rc=");
//      Serial.print(client.state());
//      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  attachInterrupt(9, interruptHandler , RISING);  
  bufferNode[0] = 'M';
  bufferNode[1] = 'X';
  bufferNode[2] = 'B';
}

void loop() {
  countDelay++;
  if(countDelay == 10000){
    interruptHandler();
    countDelay =0;
  }
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    if(Serial.available())
    {
      commandCode = 1;
      lastCommandCode = commandCode;
      stringCommandCode = lastCommandCode;
      Serial.println(lastCommandCode);
      client.publish("getBall", (char*) stringCommandCode.c_str());
    }
      client.subscribe("robot1"); 
      client.subscribe("lama");
      client.subscribe("ballXLama"); 
  }
}
  
void interruptHandler(){
//  Serial.print("Intterupt");
//  Serial1.write(packet);write
  Serial.write(bufferNode[0]);
  Serial.write(start);
  Serial.write(bufferNode[1]);
  Serial.write(ballX);
//  Serial.write(bufferNode[2]);
//  Serial.write(ballX);
}

