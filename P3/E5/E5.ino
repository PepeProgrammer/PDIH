// C++ code
//
#define LED_PIN 13
int sensor = 0;

void setup()
{
  pinMode(A0, INPUT); //configuramos el pin AO como uno de entrada
  Serial.begin(9600); //Se inicializa la comunicación serial a una velocidad de 9600
  pinMode(LED_PIN, OUTPUT); //se configura el pin 13 como una salida
}

void loop()
{
  sensor = analogRead(A0); //Leemos el valor analógico del pin A0 utilizando
  Serial.println(sensor);
  /*
  El valor del sensor se mapea desde el rango de 0 a 1023 al 0 255 que
  es el que puede controlar el pin analógico
  */
  analogWrite(LED_PIN, map(sensor, 0, 1023, 0, 255));
  delay(10);
}