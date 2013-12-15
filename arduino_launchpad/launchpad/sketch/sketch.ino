int prevLEDStatus = 0; 
int newLEDStatus = 0; 
int cmd = 0; 
int x =0;
boolean isExecuting = false;

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);  
}

void loop()
{
  if (Serial.available()) 
    {
       cmd = Serial.read() - '0'; 
       Serial.print(cmd); 
     }
     if (cmd == 0) 
       {
          digitalWrite(RED_LED, LOW);
       }
     if (cmd == 1) 
       {
         x = 0; 
         while(x < 1){
          digitalWrite(RED_LED, LOW);
          delay(100);
          digitalWrite(RED_LED, HIGH);
          delay(100);
          if (Serial.available()){
            cmd = Serial.read() - '0';
            Serial.print(cmd);
           x = 2; 
          } 
         } 
      }
         if (cmd == 2) 
       {
          digitalWrite(RED_LED, HIGH);
      }
      
      if (cmd == 3){
         digitalWrite(GREEN_LED, LOW);
      }
      if (cmd == 4){
         digitalWrite(GREEN_LED, HIGH);
      }
}
