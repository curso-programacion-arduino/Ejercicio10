#define PIN_BOTON_A 2
#define PIN_BOTON_B 3
int resultado;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int flanco_B=detectaFlancoAscendente(PIN_BOTON_B);
  
  if(flanco_B==1)
  {
    Serial.println("RESULTADO");
    resultado=random(0,5);
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

