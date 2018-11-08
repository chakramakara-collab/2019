// Processing mouse'event
void mousePressed() {
    
  //frameRate(appFrameRate);
  //redraw();
}

// Processing mouse'event
void mouseMoved() {
  
  //frameRate(appFrameRate);
  //redraw();
}

// Processing key'event
char mode = 'i';
void keyPressed() {
 if(key == 'i' || key == 'o' || key == 'p')//select robot 1
 {  
   mode = key;
 }
 if(mode == 'i')//select robot 1
 {
    if (key == 'w')//move forward
    {
      client.publish("lama", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("lama", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("lama", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("lama", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("lama", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("lama", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("lama", "*");
    }
    else if (key == ESC){
       key = 0;//disable quit on ESC
    }
    else 
    {
       key = 0;
    }
 }
 
 else if(mode == 'o')//select robot 2
 {
    if (key == 'w')//move forward
    {
      client.publish("baru", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("baru", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("baru", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("baru", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("baru", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("baru", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("baru", "*");
    }
    else if (key == ESC){
      key = 0;//disable quit on ESC
    }
    else {
      key = 0;
    }
 }

 else if(mode == 'p')//select robot 3
 {
    if (key == 'w')//move forward
    {
      client.publish("kiper", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("kiper", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("kiper", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("kiper", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("kiper", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("kiper", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("kiper", "*");
    }
    else if (key == ESC){
      key = 0;//disable quit on ESC
    }
    else {
      key = 0;
    }
 }
}
