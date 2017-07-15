#define PIN_BOTON_A 2
#define PIN_LED_1 4
#define PIN_LED_2 5
#define PIN_LED_3 6
#define PIN_LED_4 7
void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  randomSeed(A5); //genero una nueva semilla de un pin analógico al aire
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
}

void loop() {
  if (detectaFlanco(PIN_BOTON_A) == -1) {

    byte randNumber = random(4, 8);
    Serial.println(randNumber);
    digitalWrite(randNumber, HIGH);
    delay(2000);
    digitalWrite(randNumber, LOW);
  } }
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

