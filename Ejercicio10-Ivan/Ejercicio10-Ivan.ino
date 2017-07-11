#define pin 3 // pin de boton
int flanco = 0; // variable para detectar cambios de estado
#define led1 4
#define led2 5
#define led3 6
#define led4 7
int aleatorio;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  //digitalWrite(led, LOW);
  apaga();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (detectarFlanco(digitalRead(pin))) {
    case 1:
      aleatorio = random(4, 8);
      Serial.println(aleatorio);
      digitalWrite(aleatorio, HIGH);
      break;
    case 0:
      break;
    case -1:
      apaga();
      break;
  }
}

int detectarFlanco(boolean estado) { // funcion para detectar el cambio de estado del pin
  if (estado == true && flanco == 0) {
    flanco = 1;
    //pulsaciones += 10;
    Serial.println("Flanco ascendente!");
    return 1;
  }
  if (estado == false && flanco == 1) { // si pin deja de estar high ponemos el flanco a 0
    flanco = 0;
    Serial.println("Flanco descendente!");
    return -1;
  }
  if (estado == true && flanco == 1) {
    return 0;
  }
}
void apaga() {
  for (int i = led1; i <= led4; i++) {
    digitalWrite(i, LOW);
  }
}
