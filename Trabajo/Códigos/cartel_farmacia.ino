#include <LiquidCrystal.h>
#include <DHT.h>
#include <Wire.h>
#include <RTClib.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// DHT11 en el pin 10
DHT dht(10, DHT11);

// RTC DS3231 (I2C en A4/A5)
RTC_DS3231 rtc;

// Carácter personalizado: cruz de farmacia
byte cruzFarmacia[8] = {
  0b00100,
  0b00100,
  0b11111,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};

// Carácter personalizado: símbolo de grado
byte grado[8] = {
  0b01100,
  0b10010,
  0b10010,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

// Carácter personalizado: gota
byte gota[8] = {
  0b00100,
  0b00100,
  0b01010,
  0b01010,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};

// Carácter personalizado: relojito
byte reloj[8] = {
  0b00000,
  0b01110,
  0b10101,
  0b10111,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

unsigned long ultimoParpadeo  = 0;
unsigned long ultimoCambioMsg = 0;
unsigned long ultimaLecturaDHT = 0;
unsigned long ultimaActHora   = 0;
bool cruzVisible  = true;
int  mensajeActual = 0;

float tempC    = 0.0;
float humedad  = 0.0;

const int INTERVALO_PARPADEO    = 600;     // ms
const int INTERVALO_MENSAJE     = 3000;    // ms
const int INTERVALO_LECTURA_DHT = 2500;    // DHT11 necesita >=2s
const int INTERVALO_HORA        = 1000;    // refrescar reloj cada segundo

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, cruzFarmacia);
  lcd.createChar(1, grado);
  lcd.createChar(2, gota);
  lcd.createChar(3, reloj);

  dht.begin();

  // Inicializar el RTC
  if (!rtc.begin()) {
    lcd.setCursor(0, 0); lcd.print("Error RTC!");
    while (true) delay(1000);
  }

  // Si el RTC perdio la hora (pila agotada),
  // se ajusta a la fecha/hora de compilación
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.setCursor(0, 0); 
  lcd.print("   FARMACIA");
  lcd.setCursor(0, 1); 
  lcd.print("   La Chana");
  delay(1500);

  leerSensor();
  lcd.clear();
}

void loop() {
  unsigned long ahora = millis();

  // Lectura periodica del DHT11
  if (ahora - ultimaLecturaDHT >= INTERVALO_LECTURA_DHT) {
    ultimaLecturaDHT = ahora;
    leerSensor();
  }

  // Parpadeo de las cruces
  if (ahora - ultimoParpadeo >= INTERVALO_PARPADEO) {
    ultimoParpadeo = ahora;
    cruzVisible = !cruzVisible;
    dibujarCruces();
  }

  // Si el mensaje actual es la hora, la refrescamos cada segundo
  if (mensajeActual == 2 && ahora - ultimaActHora >= INTERVALO_HORA) {
    ultimaActHora = ahora;
    mostrarHora();
  }

  // Cambio de mensaje
  if (ahora - ultimoCambioMsg >= INTERVALO_MENSAJE) {
    ultimoCambioMsg = ahora;
    mensajeActual = (mensajeActual + 1) % 5;
    mostrarMensaje();
  }
}

void leerSensor() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (!isnan(t)) tempC   = t;
  if (!isnan(h)) humedad = h;
}

void dibujarCruces() {
  lcd.setCursor(0, 0);  
  lcd.write(cruzVisible ? (uint8_t)0 : ' ');
  lcd.setCursor(15, 0); 
  lcd.write(cruzVisible ? (uint8_t)0 : ' ');
  lcd.setCursor(0, 1);  
  lcd.write(cruzVisible ? (uint8_t)0 : ' ');
  lcd.setCursor(15, 1); 
  lcd.write(cruzVisible ? (uint8_t)0 : ' ');
}

void mostrarMensaje() {
  limpiarCentro();

  switch (mensajeActual) {
    case 0:
      lcd.setCursor(2, 0); 
      lcd.print("  FARMACIA");
      lcd.setCursor(2, 1); 
      lcd.print("  La Chana");
      break;
    case 1:
      lcd.setCursor(2, 0); 
      lcd.print(" ABIERTO");
      lcd.setCursor(2, 1); 
      lcd.print("  24 HORAS");
      break;
    case 2:
      mostrarHora();
      break;
    case 3:
      lcd.setCursor(2, 0); 
      lcd.print(" Temperatura");
      lcd.setCursor(5, 1);
      lcd.print(tempC, 1);
      lcd.write((uint8_t)1); // °
      lcd.print("C");
      break;
    case 4:
      lcd.setCursor(2, 0); 
      lcd.print("  Humedad ");
      lcd.write((uint8_t)2); // gota
      lcd.setCursor(5, 1);
      lcd.print(humedad, 0);
      lcd.print(" %");
      break;
  }
}

void mostrarHora() {
  DateTime ahora = rtc.now();
  limpiarCentro();

  // Fila superior: icono de reloj + fecha
  lcd.setCursor(2, 0);
  lcd.write((uint8_t)3);
  lcd.print(' ');
  imprimirDosDigitos(ahora.day());    
  lcd.print('/');
  imprimirDosDigitos(ahora.month());   
  lcd.print('/');
  lcd.print(ahora.year());

  // Fila inferior: hora centrada
  lcd.setCursor(4, 1);
  imprimirDosDigitos(ahora.hour());    
  lcd.print(':');
  imprimirDosDigitos(ahora.minute());  
  lcd.print(':');
  imprimirDosDigitos(ahora.second());
}

void imprimirDosDigitos(int n) {
  if (n < 10) lcd.print('0');
  lcd.print(n);
}

void limpiarCentro() {
  for (int fila = 0; fila < 2; fila++) {
    lcd.setCursor(1, fila);-
    for (int c = 1; c <= 14; c++) lcd.print(' ');
  }
}
