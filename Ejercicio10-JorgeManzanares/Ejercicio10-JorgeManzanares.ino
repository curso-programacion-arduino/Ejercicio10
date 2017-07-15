#define PIN_BOTON_A 2
#define PIN_BOTON_B 3
#define PIN_LED_1 4
#define PIN_LED_2 5 //PWM
#define PIN_LED_3 6 //PWM
#define PIN_LED_4 7
int resultado,resultado_anterior,i;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
}

void loop() {
  int flanco_B = detectaFlancoAscendente(PIN_BOTON_B);

  if (flanco_B == 1)
  {
    Serial.println("RESULTADO");
    
    resultado = random(4, 8);
    digitalWrite(resultado_anterior,LOW);
    digitalWrite(resultado, HIGH);
      resultado_anterior=resultado;
  }
  Serial.println(resultado);
  delay(50);
  // put your main code here, to run repeatedly:

}
boolean detectaFlancoAscendente(int pin) {
  static boolean anterior_estado = digitalRead(pin);
  boolean estado = digitalRead(pin);

  if ((anterior_estado != estado) && (estado == HIGH)) {
    anterior_estado = estado;
    return true;
  }
  else {
    anterior_estado = estado;
    return false;
  }
}

boolean detectaFlancoDescendente(int pin) {
  static boolean anterior_estado = digitalRead(pin);
  boolean estado = digitalRead(pin);

  if ((anterior_estado != estado) && (estado == LOW)) {
    anterior_estado = estado;
    return true;
  }
  else {
    anterior_estado = estado;
    return false;
  }
}

