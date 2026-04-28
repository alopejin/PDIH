long duracion; //Definimos una variable para la duración
int distancia; //Definimos una variable para la distancia

void setup() {
  //Configuración inicial:
  pinMode(12, OUTPUT);  //pin 12 conectado al disparador
  pinMode(13, INPUT);   //pin 13 conectado al receptor
  pinMode(11, OUTPUT);  //pin 11 conectado al altavoz
  Serial.begin(9600); //Iniciamos comunicación con el monitor serie (para poder imprimir las distancias)
}

 // Ejecución en bucle:
void loop() {
  //Enviamos una señal durante 10 microsegundos
  digitalWrite(12, LOW); //Primero aseguramos que no envía nada
  delayMicroseconds(2); //Esperamos 2 microsegundos
  digitalWrite(12, HIGH);//Enviamos la señal
  delayMicroseconds(10); //Finaliza tras 10 microsegundos
  digitalWrite(12, LOW); //Dejamos de enviar

  duracion = pulseIn(13, HIGH, 30000); //Leemos la duración de la señal

  distancia = duracion * 0.034 / 2; //Calculamos la distancia en cm

  Serial.print("Distancia: ");
  Serial.print(distancia); //Sacamos la distancia por pantalla
  Serial.println(" cm");

  //Variamos el tono del altavoz según la distancia
  if (distancia > 0 && distancia <= 40){ //Si la distancia es de entre 0 y 40 cm
    tone(11, 2000); //El altavoz suena a 2000 Hz
  } 
  else if (distancia > 40 && distancia <= 100){ //Si es de entre 40 y 100 cm
    tone(11, 1000); //El altavoz suena a 1000 Hz
  }
  else if (distancia > 100 && distancia <= 150){ //Entre 100 y 150 cm
    tone(11, 500); //El altavoz suena a 500 Hz
  }
  else{
    noTone(11); // En cualquier otro caso no suena
  }

  delay(150); //Esperamos antes de que el sensor dispare de nuevo
}