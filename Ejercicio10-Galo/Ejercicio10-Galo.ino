#define BOTON 2
#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

long randNumber;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Iniciando pines..."));

  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  randomSeed(analogRead(A3)); //semilla con pin analógico libre
}

void loop() {
  if (detectaFlanco(BOTON) == -1) {

    byte randNumber = random(LED1, LED4+1);
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
  for (int i = LED1; i <= LED4; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
  }
  for (int i = LED4; i >= LED1; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
  }
  digitalWrite(pin_led, HIGH);
  Serial.println("Enciendo pin: " + (String)pin_led);
}
