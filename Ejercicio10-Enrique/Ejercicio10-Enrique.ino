#define PIN_BOTON_A 2
#define PIN_LED_1 4
#define PIN_LED_2 5 //PWM
#define PIN_LED_3 6 //PWM
#define PIN_LED_4 7

void setup() {
  //Inicializo puerto serie
  Serial.begin(9600);

  //Inicializo Pines
  Serial.println(F("Inicializando pines digitales..."));
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);

  randomSeed(A5); //genero una nueva semilla de un pin analógico al aire

}

void loop() {
  if (detectaFlanco(PIN_BOTON_A) == -1) {

    byte randNumber = random(1, 5);
    Serial.println(randNumber);
    iluminaLed(randNumber);
  }
  delay(50); //evitar rebotes
}

int detectaFlanco(int pin) {
  //Devuelve 1 flanco ascendente, -1 flanco descendente y 0 si no hay nada
  static boolean anterior_estado = digitalRead(pin);
  boolean estado = digitalRead(pin);

  if (anterior_estado != estado) {
    if (estado == HIGH) {
      anterior_estado = estado;
      return 1;
    }
    else {
      anterior_estado = estado;
      return -1;
    }
  }
  else {
    anterior_estado = estado;
    return 0;
  }
}

void iluminaLed(int pin_led) {
  for (int i = PIN_LED_1; i <= PIN_LED_4; i++) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    delay(500);
  }
  for (int i = PIN_LED_4; i <= PIN_LED_1; i--) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    delay(500);
  }
  digitalWrite(pin_led, HIGH);
}
