// C++ code
//
int pulsador =0; 

void setup()
{
  
  pinMode(13, OUTPUT); // led rojo
  pinMode(12, OUTPUT);  // led amarillo
  pinMode(11, OUTPUT); // led verde

  pinMode(7,INPUT); //pulsador
}

void loop()
{
  pulsador = digitalRead(7);
  if( pulsador == HIGH) { // Si el pulsador está pulsado
  	digitalWrite(13, HIGH);
  	digitalWrite(12, LOW);
  	digitalWrite(11, LOW);
  } else {
	digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);

    delay(500); // Wait for 500 millisecond(s)

    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);

    delay(500); // Wait for 500 millisecond(s)
  }
  
}