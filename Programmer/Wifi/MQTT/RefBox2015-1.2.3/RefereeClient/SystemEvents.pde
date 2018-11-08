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
      client.publish("robot1/no21", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("robot1/no21", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("robot1/no21", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("robot1/no21", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("robot1/no21", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("robot1/no21", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("robot1/no21", "*");
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
      client.publish("robot1/no12", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("robot1/no12", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("robot1/no12", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("robot1/no12", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("robot1/no12", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("robot1/no12", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("robot1/no12", "*");
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
      client.publish("robot1/no1", "@");
    }
    else if (key == 's')//move backward
    {
      client.publish("robot1/no1", "#");
    }
    else if (key == 'a')//move left
    {
      client.publish("robot1/no1", "$");
    }
    else if (key == 'd')//move right
    {
      client.publish("robot1/no1", "%");
    }
    else if (key == 'q')//rotate anticlockwise
    {
      client.publish("robot1/no1", "^");
    }
    else if (key == 'e')//rotate clockwise
    {
      client.publish("robot1/no1", "&");
    }
    else if (key == 'f')//stop
    {
      client.publish("robot1/no1", "*");
    }
    else if (key == ESC){
      key = 0;//disable quit on ESC
    }
    else {
      key = 0;
    }
 }
}
