
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int buttonA = 2;
int buttonB = 3;
int contador = 0;

const int ledR =  5;
const int ledG =  6;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("!Hola, Ipsy!");
  lcd.setCursor(0, 1);
  lcd.print("Sientate a jugar");


  pinMode(buttonA, INPUT_PULLUP); 
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  //Esperamos 5 segundos
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);

  if (contador == 0){
  delay(5000);
  }
  else if (contador == 3){
  transicion();
  lcd.print("Una pista,");
  lcd.setCursor(0, 1);
  lcd.print("Usa dos deditos");
  //delay(100);
  }
  //Transicion de pantalla
  
  if (contador!=3){
  lcd.clear();
  delay(200);
  lcd.print("Pulsa botones");
  lcd.setCursor(0, 1);
  lcd.print("Y desciframe");
  }
  
  while (digitalRead(buttonA) == HIGH && digitalRead(buttonB) == HIGH){
    // Aquí puedes dejarlo vacío o agregar un pequeño delay para evitar
    // sobrecargar el procesador
    delay(50);
  }

  if (digitalRead(buttonA) == LOW && digitalRead(buttonB) == LOW){
    transicion();
    digitalWrite(ledG, HIGH);
    
    lcd.print("No sabes cuan");
    lcd.setCursor(0, 1);
    lcd.print("especial eres");
    delay(3000);
    transicion();

    lcd.print("Todo mi esfuerzo");
    lcd.setCursor(0, 1);
    lcd.print("lo hago por ti");
    delay(3000);
    transicion();

    lcd.print("Eres el amor");
    lcd.setCursor(0, 1);
    lcd.print("de mi vida <3");
    delay(2000);
    digitalWrite(ledG, LOW);
    delay(2000);
    while (digitalRead(buttonA) == HIGH && digitalRead(buttonB) == HIGH){
    // Aquí puedes dejarlo vacío o agregar un pequeño delay para evitar
    // sobrecargar el procesador
      delay(50);
    }

  }
  else if (digitalRead(buttonA)==LOW) {
    transicion();
    digitalWrite(ledR, HIGH);
    lcd.print("Te amo mucho");
    lcd.setCursor(0, 1);
    lcd.print("Pero fallaste");
    while(digitalRead(buttonA) == LOW){
    }

  }else if (digitalRead(buttonB)==LOW) {
    transicion();
    digitalWrite(ledR, HIGH);
    lcd.print("Eres lista");
    lcd.setCursor(0, 1);
    lcd.print("Pero no es aqui");
    while(digitalRead(buttonB) == LOW){
    }
  }

  delay(2000);
  contador++;
}

// Función para realizar la transición (limpiar pantalla y esperar)
void transicion() {
  lcd.clear();  // Limpiar la pantalla
  delay(200);   // Esperar 200 ms
}
