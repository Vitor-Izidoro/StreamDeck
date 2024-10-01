#include <Keyboard.h>

// Define os pinos onde os botões estão conectados
const int buttonPin2 = 2;
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;
const int buttonPin6 = 6;

// Variáveis para armazenar o estado anterior dos botões
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;
int lastButtonState5 = HIGH;
int lastButtonState6 = HIGH;

// Tempo de debounce
unsigned long debounceDelay = 50;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;

void setup() {
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // Lê o estado atual de cada botão
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  int buttonState6 = digitalRead(buttonPin6);

  unsigned long currentTime = millis();
  
  // Verifica o botão 3 com debounce
  if (buttonState3 != lastButtonState3 && (currentTime - lastDebounceTime3) > debounceDelay) {
    lastDebounceTime3 = currentTime;
    if (buttonState3 == LOW) {
      // Verifica se o botão 4 está pressionado simultaneamente
      if (buttonState4 == LOW) {
        // Ambos os botões 3 e 4 pressionados ao mesmo tempo
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.print("steam");
        delay(250);
        Keyboard.press(KEY_RETURN);
        delay(100);
        Keyboard.releaseAll();
        Serial.println("Botões 3 e 4 pressionados juntos");
      } else {
        // Apenas o botão 3 foi pressionado
        Keyboard.press(KEY_LEFT_GUI); 
        delay(50);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.print("google");
        delay(250);
        Keyboard.press(KEY_RETURN);
        delay(100);
        Keyboard.releaseAll();
        Serial.println("Botão 3 pressionado");
      }
    }
  }

  // Verifica o botão 4 com debounce
  if (buttonState4 != lastButtonState4 && (currentTime - lastDebounceTime4) > debounceDelay) {
    lastDebounceTime4 = currentTime;
    if (buttonState4 == LOW && buttonState3 != LOW) {
      // Apenas o botão 4 foi pressionado
      Keyboard.press(KEY_LEFT_GUI); 
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      Keyboard.print("meu computador");
      delay(250);
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
      Serial.println("Botão 4 pressionado");
    }
  }

  // Verifica os outros botões normalmente
  if (buttonState2 == LOW && lastButtonState2 == HIGH) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    Serial.println("Botão 2 pressionado (Ctrl + V)");
  }

  if (buttonState5 == LOW && lastButtonState5 == HIGH) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(100);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.releaseAll();
    Serial.println("Botão 5 pressionado (Alt + F4)");
  }

  if (buttonState6 == LOW && lastButtonState6 == HIGH) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.release(KEY_TAB);
    Keyboard.release(KEY_LEFT_ALT);
    Serial.println("Botão 6 pressionado (Alt + Tab)");
    Keyboard.releaseAll();
  }

  // Atualiza o estado anterior de cada botão
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;
  lastButtonState5 = buttonState5;
  lastButtonState6 = buttonState6;

  delay(50);  // Debounce simples para evitar leituras erradas
}
