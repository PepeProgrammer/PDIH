// C++ code
//
// Definimos el pin para el sensor ultrasónico (equivalente a SIG)
#define SIG_PIN  12
#define BUZ_PIN  11
int pulso; 
float distancia;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop()
{
  pinMode(SIG_PIN,OUTPUT);
  digitalWrite(SIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(SIG_PIN,LOW);
  pinMode(SIG_PIN,INPUT);
  pulso = pulseIn(SIG_PIN,HIGH); //medimos la duración del pulso untrasónico
  distancia = (pulso * 0.0343) / 2; //asumimos que el sonido viaja a una velocidad de 343 metros por segundo en el aire
  
  if(distancia < 200) {
  	digitalWrite(LED_BUILTIN, HIGH);
    tone(BUZ_PIN,1000); //se activa el buzzer 
  } else { //se apaga el buzzer
  	digitalWrite(LED_BUILTIN, LOW);
    noTone(BUZ_PIN);
  }
  
  delay(10);
}