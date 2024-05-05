// C++ code
//
void setup()
{
  pinMode(13, OUTPUT); //led
  pinMode(12, OUTPUT);  //led
  pinMode(11, OUTPUT); //led
  pinMode(10, OUTPUT); //led



}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);



  delay(100); // Wait for 500 millisecond(s)
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(100); // Wait for 500 millisecond(s)
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  
  delay(100); // Wait for 500 millisecond(s)
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  delay(100);
    
      digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  
  delay(100); // Wait for 500 millisecond(s)
  
   digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(100); // Wait for 500 millisecond(s)
  
    digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);


  

}