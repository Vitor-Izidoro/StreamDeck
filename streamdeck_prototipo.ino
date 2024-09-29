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

void setup() {
  // Inicializa os pinos dos botões como entrada com pull-up interno
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  
  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);
  // Inicializa a biblioteca de teclado
  Keyboard.begin();
}

void loop() {
  // Lê o estado atual de cada botão (LOW quando pressionado devido ao pull-up)
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  int buttonState6 = digitalRead(buttonPin6);

  // Verifica se o botão 2 foi pressionado
  if (buttonState2 == LOW && lastButtonState2 == HIGH) {
    // Simula a combinação de teclas Ctrl + V
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();  
    Serial.println("Botão 2 pressionado (Ctrl + V simulado)");
  }

  // Verifica se o botão 3 foi pressionado
  if (buttonState3 == LOW && lastButtonState3 == HIGH) {
    // Aqui você pode colocar a função desejada para o botão 3
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win (esquerda)
    delay(50);
    Keyboard.releaseAll();
    delay(100); // Espera um pouco para a caixa de diálogo Executar abrir completamente
    Keyboard.print("google");
    delay(250);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
    

  }

  // Verifica se o botão 4 foi pressionado
  if (buttonState4 == LOW && lastButtonState4 == HIGH) {
    // Aqui você pode colocar a função desejada para o botão 4Keyboard.press(KEY_LEFT_GUI); 
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win (esquerda)
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("meu computador");
    delay(250);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
  }

  // Verifica se o botão 5 foi pressionado
  if (buttonState5 == LOW && lastButtonState5 == HIGH) {
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win (esquerda)
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("camera");
    delay(250);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
  }

  // Verifica se o botão 6 foi pressionado
  if (buttonState6 == LOW && lastButtonState6 == HIGH) {
    // Simula a combinação de teclas Alt + Tab
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.release(KEY_TAB);
    Keyboard.release(KEY_LEFT_ALT);
    Serial.println("Botão 6 pressionado (Alt + Tab simulado)");
    Keyboard.releaseAll();
  }

  // Atualiza o estado anterior de cada botão
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;
  lastButtonState5 = buttonState5;
  lastButtonState6 = buttonState6;

  // Pequeno atraso para evitar a leitura errada dos botões
  delay(50);
}
