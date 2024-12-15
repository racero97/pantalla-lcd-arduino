//Libreria necesaria para la pantalla
#include <LiquidCrystal.h>

//Inicializamos todos los pines que controlan la pantalla
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Inicializamos los pines de los botones y leds
int buttonA = 2;
int buttonB = 3;

const int ledR =  5;
const int ledG =  6;

//Añadimos un contador para dar pistas si el jugador falla
int contador = 0;

void setup() {
  //Setup de la disposicion  de la pantalla y primer mensaje
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("!Hola Player!");
  lcd.setCursor(0, 1);
  lcd.print("Sientate a jugar");

  //Inicializamos los input de los botones y output de los leds
  pinMode(buttonA, INPUT_PULLUP); 
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  //Apagamos los leds al inicio del bucle siempre
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);

  //Esperamos 5 segundos si es cuando se inicia el programa
  if (contador == 0){
  delay(5000);
  }
  //Si ya has fallado 3 veces te va a salir una pista en pantalla
  else if (contador == 3){
  transicion();
  lcd.print("Una pista,");
  lcd.setCursor(0, 1);
  lcd.print("Usa dos deditos");
  //delay(100);
  }
  
  //Cuando no hay pistas aparece un mensaje por defecto
  if (contador!=3){
  transicion();
  lcd.print("Pulsa botones");
  lcd.setCursor(0, 1);
  lcd.print("Y desciframe");
  }

  //Si ambos botones estan sin pulsar, no va a ocurrir nada
  while (digitalRead(buttonA) == HIGH && digitalRead(buttonB) == HIGH){
    //pequeño delay para evitar sobrecargar el procesador
    delay(50);
  }
  //Si se pulsan los dos botones a la vez ganas el juego y sale el led verde junto a un mensaje
  if (digitalRead(buttonA) == LOW && digitalRead(buttonB) == LOW){
    transicion();
    digitalWrite(ledG, HIGH);
    
    lcd.print("¡Enhorabuena!!");
    lcd.setCursor(0, 1);
    lcd.print("¡Has ganado!");
    delay(3000);
    transicion();

    lcd.print("Ahora debes");
    lcd.setCursor(0, 1);
    lcd.print("recoger tu premio");
    delay(3000);
    transicion();

    lcd.print("El cual es");
    lcd.setCursor(0, 1);
    lcd.print("un aplauso!");
    delay(2000);
    digitalWrite(ledG, LOW);
    delay(2000);
    while (digitalRead(buttonA) == HIGH && digitalRead(buttonB) == HIGH){
    // Buble infinito hasta que se toque algun boton de nuevo y volver al juego
      delay(50);
    }
  }
  //Si solo pulsas el boton A perdiste, sigue el flujo y se enciende el led rojo
  else if (digitalRead(buttonA)==LOW) {
    transicion();
    digitalWrite(ledR, HIGH);
    lcd.print("Juegas bien");
    lcd.setCursor(0, 1);
    lcd.print("Pero fallaste");
    //Mantenemos el texto mientras tenga el boton pulsado
    while(digitalRead(buttonA) == LOW){
      delay(50);
    }
  //Lo mismo pasa con el boton B
  }else if (digitalRead(buttonB)==LOW) {
    transicion();
    digitalWrite(ledR, HIGH);
    lcd.print("Eres listo");
    lcd.setCursor(0, 1);
    lcd.print("Pero no es aqui");
    while(digitalRead(buttonB) == LOW){
      delay(50);
    }
  }
  //Pequeño delay para que de tiempo de leer el texto y se suma 1 al numero de intentos
  delay(1000);
  contador++;
}

// Función para realizar la transición (limpiar pantalla y esperar)
void transicion() {
  lcd.clear();  // Limpiar la pantalla
  delay(200);   // Esperar 200 ms
}
