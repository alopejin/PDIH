void setup() {
  //Configuración inicial:
  pinMode(13, OUTPUT); //pin 13 conectado al LED rojo
  pinMode(12, OUTPUT); //pin 12 conectado al LED amarillo
  pinMode(11, OUTPUT); //pin 11 conectado al LED verde
  pinMode(7, INPUT); //pin 7 conectado al pulsador
}

void loop() {
  //Ejecución en bucle:
  if (digitalRead(7) == HIGH){ //comprueba si el botón está pulsado
    digitalWrite(13, HIGH); //encendemos el LED rojo
    digitalWrite(12, LOW); //apagamos el LED amarillo
    digitalWrite(11, LOW); //apagamos el LED verde
    delay(1500); //esperamos 1500 ms (1,5 segundos)
  }
  else{ //si el boton no está pulsado
  digitalWrite(13, LOW); //apagamos el LED rojo
  digitalWrite(12, HIGH); //encendemos el LED amarillo
  digitalWrite(11, LOW); //apagamos el LED verde
  delay(1500); //esperamos 1500 ms
  digitalWrite(13, LOW); //apagamos el LED rojo
  digitalWrite(12, LOW); //apagamos el LED amarillo
  digitalWrite(11, HIGH); //encendemos el LED verde
  delay(1500); //esperamos 1500 ms
  }
}
