#define PIN_BOTON_A 2
#define PIN_LED_1 4
#define PIN_LED_2 5 //PWM
#define PIN_LED_3 6 //PWM
#define PIN_LED_4 7

unsigned long duracion = 0;

void setup() {
 Serial.begin(9600);

 //Inicializo Pines
 Serial.println(F("Inicializando pines digitales..."));
 pinMode(PIN_BOTON_A, INPUT_PULLUP);
 pinMode(PIN_LED_1, OUTPUT);
 pinMode(PIN_LED_2, OUTPUT);
 pinMode(PIN_LED_3, OUTPUT);
 pinMode(PIN_LED_4, OUTPUT);
}

void loop() {
 int flanco = detectaFlanco(PIN_BOTON_A);
 int numero;
 if (flanco == 1) {
   Serial.println("Flanco ascendente");
   numero = random(1, 4);
 Serial.println(numero);
   if (numero == 1) {
     digitalWrite(PIN_LED_1, HIGH);
   }
   if (numero == 2) {
     digitalWrite(PIN_LED_2, HIGH);
   }
   if (numero == 3) {
     digitalWrite(PIN_LED_3, HIGH);
   }
   if (numero == 4) {
     digitalWrite(PIN_LED_4, HIGH);
   }
   delay(100);
   digitalWrite(PIN_LED_1, LOW);
   digitalWrite(PIN_LED_2, LOW);
   digitalWrite(PIN_LED_3, LOW);
   digitalWrite(PIN_LED_4, LOW);
 }
 if (flanco == -1)
   Serial.println("Flanco descendente");
 

 delay(100);
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
   return 0;
 }
}
