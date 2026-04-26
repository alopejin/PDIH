void setup() {
  //Configuración inicial:
  pinMode(13, OUTPUT); //pin 13 conectado al primer LED rojo
  pinMode(12, OUTPUT); //pin 12 conectado al segundo LED rojo
  pinMode(11, OUTPUT); //pin 11 conectado al tercer LED rojo
  pinMode(10, OUTPUT); //pin 10 conectado al cuarto LED rojo
}

void loop() {
  //Ejecución en bucle:
  digitalWrite(13, HIGH); //encendemos el primer LED rojo
  digitalWrite(12, LOW);  //apagamos el segundo LED rojo
  digitalWrite(11, LOW); //apagamos el tercer LED rojo
  digitalWrite(10, LOW); //apagamos el cuarto LED rojo
  delay(200); //esperamos 200 ms (0,2 segundos)
  digitalWrite(13, LOW); //apagamos el primer LED rojo
  digitalWrite(12, HIGH); //encendemos el segundo LED rojo
  digitalWrite(11, LOW); //apagamos el tercer LED rojo
  digitalWrite(10, LOW); //apagamos el cuarto LED rojo
  delay(200); //esperamos 200 ms
  digitalWrite(13, LOW); //apagamos el primer LED rojo
  digitalWrite(12, LOW); //apagamos el segundo LED rojo
  digitalWrite(11, HIGH); //encendemos el tercer LED rojo
  digitalWrite(10, LOW); //apagamos el cuarto LED rojo
  delay(200); //esperamos 200 ms
  digitalWrite(13, LOW); //apagamos el primer LED rojo
  digitalWrite(12, LOW); //apagamos el segundo LED rojo
  digitalWrite(11, LOW); //apagamos el tercer LED rojo
  digitalWrite(10, HIGH); //encendemos el cuarto LED rojo
  delay(200); //esperamos 200 ms
}