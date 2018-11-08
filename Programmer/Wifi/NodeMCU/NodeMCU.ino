#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

//#define wifi_ssid "EC2"
//#define wifi_password "ju4r4ju4r4"
//#define wifi_ssid "Lenovo A6010_AP"
//#define wifi_password "44444444"
#define wifi_ssid "123"
#define wifi_password "11111111"
//#define wifi_ssid "ChakraMakara"
//#define wifi_password "susah303"

//#define mqtt_server "10.5.75.228"
//#define mqtt_server "192.168.43.49"
//#define mqtt_server "192.168.43.154"
#define mqtt_server "192.168.43.36"
//IPAddress mqtt_server(192,168,43,36);

char data[16];
float newTemp = 1;
long lastMsg = 0;
float temp = 0.0;
char start= 'S';
int countDelay=0;
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    start = (char)payload[i];
  }
  Serial.println();
}


WiFiClient espClient;
PubSubClient client(espClient);
char message_buff[100];



void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);
  

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
  
    if (client.connect("espClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  attachInterrupt(9, interruptHandler , RISING);  
  
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
//      temp = newTemp;
//      Serial.print("x:");
//      Serial.println(String(temp).c_str());
//      client.publish("robot2", String(temp).c_str(), true);
//      newTemp++;
//      temp = newTemp;
//      Serial.print("y:"); 
//      Serial.println(String(temp).c_str());
//      client.publish("robot2", String(temp).c_str(), true);
      
      client.subscribe("robot1"); 
//      client.subscribe("outTopic");
  }
}
  
void interruptHandler(){
//  Serial.print("Intterupt");
  Serial1.write(start);
}

