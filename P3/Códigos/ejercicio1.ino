void setup() {
  //Configuración inicial:
  pinMode(13, OUTPUT); //pin 13 conectado al LED rojo
  pinMode(12, OUTPUT); //pin 12 conectado al LED amarillo
  pinMode(11, OUTPUT); //pin 11 conectado al LED verde
}

void loop() {
  //Ejecución en bucle:
  digitalWrite(13, HIGH); //encendemos el LED rojo
  digitalWrite(12, LOW); //apagamos el LED amarillo
  digitalWrite(11, LOW); //apagamos el LED verde
  delay(1500); //esperamos 1500 ms (1,5 segundos)
  digitalWrite(13, LOW); //apagamos el LED rojo
  digitalWrite(12, HIGH); //encendemos el LED amarillo
  digitalWrite(11, LOW); //apagamos el LED verde
  delay(1500); //esperamos 1500 ms
  digitalWrite(13, LOW); //apagamos el LED rojo
  digitalWrite(12, LOW); //apagamos el LED amarillo
  digitalWrite(11, HIGH); //encendemos el LED verde
  delay(1500); //esperamos 1500 ms
}