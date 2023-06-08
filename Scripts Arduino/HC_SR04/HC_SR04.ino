const int Trigger = 14;
const int Echo = 12;

double distancia;

double fnc_ultrasonic_dist(int _trig, int _ech){
  unsigned long dur = 0;
  digitalWrite(_trig, LOW); // Para generar pulso limpio
  delayMicroseconds(5);

  digitalWrite(_trig, HIGH); // Generamos Trigger
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  dur = pulseIn(_ech, HIGH, 18000);
  if(dur==0)return 999.0;
  return (dur/58.3);
}


void setup() {
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();
}


void loop() {
  distancia = fnc_ultrasonic_dist(Trigger, Echo);

  Serial.print(String("Distancia: "));
  Serial.print(distancia);
  Serial.println(String(" cm"));

  delay(500);

}
