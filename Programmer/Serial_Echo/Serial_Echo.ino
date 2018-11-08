 void setup()  
 {  
  Serial.begin(9600);  
  pinMode(LED_BUILTIN, OUTPUT);
 }  
 void loop()  
 {  
  if(Serial.available())  
  {  
   char c = Serial.read();  
   Serial.print(c);  
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  }  
 }  
