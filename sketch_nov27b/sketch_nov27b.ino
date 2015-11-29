  //Read sensor value
    sensorValue = digitalRead(7); 

    //white detected 
    if(sensorValue) {
      digitalWrite(LMF,OFF);
      digitalWrite(LMR,ON);
      digitalWrite(RMF,ON);
   }
  
    //black detected
    if(!sensorValue) {
      digitalWrite(LMF,ON);
      digitalWrite(RMF,OFF);
      digitalWrite(RMR,ON);
   }
