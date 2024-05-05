// C++ code
//
void setup()
{
  pinMode(13, OUTPUT); //Led rojo
  pinMode(12, OUTPUT);  //Led amarillo
  pinMode(11, OUTPUT); //Led verde


}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);


  delay(500); // Wait for 500 millisecond(s)
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);

  delay(500); // Wait for 500 millisecond(s)
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  
  delay(500); // Wait for 500 millisecond(s)
}