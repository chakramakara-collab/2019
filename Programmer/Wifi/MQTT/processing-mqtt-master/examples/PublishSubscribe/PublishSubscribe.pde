// This example sketch connects to shiftr.io
// and sends a message on every keystroke.
//
// After starting the sketch you can find the
// client here: https://shiftr.io/try.
//
// Note: If you're running the sketch via the
// Android Mode you need to set the INTERNET
// permission in Android > Sketch Permissions.
//
// by Joël Gähwiler
// https://github.com/256dpi/processing-mqtt

import mqtt.*;

MQTTClient client;

void setup() {
  client = new MQTTClient(this);
  client.connect("tcp://localhost:1883");
  client.subscribe("robot1");
  // client.unsubscribe("/example");
}

void draw() {}

void keyPressed() {
  client.publish("robot1", "world");
}

void messageReceived(String topic, byte[] payload) {
  println("new message: " + topic + " - " + new String(payload));
}