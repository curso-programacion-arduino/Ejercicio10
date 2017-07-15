#define PIN_BOTON_B 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BOTON_B, INPUT);
}

void loop() {

  int flanco = detectaFlanco(PIN_BOTON_B);

  if (flanco == 1) {
    int numero = random(1, 5);
    Serial.println (numero);

  }



}




int detectaFlanco (int pin) {
  static boolean anterior_b = digitalRead(pin);
  boolean estado_b = digitalRead(pin);
  int flancoEstado;

  if (anterior_b != estado_b) {
    anterior_b = estado_b;
    if (estado_b == HIGH) {  //flanco ascendente pull-down
      delay (50);
      return flancoEstado = 1;

    }

    else {
      delay (50);
      return flancoEstado = -1;
    }
  }

  else
    delay (50);
  return 0;


}

