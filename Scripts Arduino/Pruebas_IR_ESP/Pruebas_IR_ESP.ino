void setup()
{
  pinMode(5, INPUT);

	Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

}


void loop()
{
	yield();

  	Serial.println(String("Inicio"));
  	if (digitalRead(5)) {
  		Serial.println(String("Detectando linea"));
  	}
  	else {
  		Serial.println(String("Fuera de linea"));
  	}
    delay(500);

}