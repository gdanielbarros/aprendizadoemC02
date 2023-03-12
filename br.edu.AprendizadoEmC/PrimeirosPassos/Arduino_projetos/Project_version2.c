#include <Keypad.h>

const byte ROWS = 4; //quatro linhas
const byte COLS = 4; //três colunas
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //conectar aos pinos das linhas do teclado
byte colPins[COLS] = {9, 8, 7,6}; //conectar aos pinos das colunas do teclado

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int sensor;
char senha[6] = {'1','2','3','4','5','6'};
char senha2[7] = {0}; //inicializar todos os elementos com zero
char chute;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(18, INPUT);
}

void loop() {
  //ler uma tecla do teclado
  chute = keypad.getKey();
  
  //se uma tecla foi pressionada, adicionar à matriz senha2
  if (chute != 0) {
    //adicionar um atraso. É pra evitar que varias declas entre
    delay(100);
    
    senha2[i] = chute;
    Serial.println(chute);
    i++;
  }

  //sendo 6 dígitos será inseridos, comparar senha2 e senha
  if (strlen(senha2) == 6) {
    //usar strncmp para comparar as duas matrizes
    if (strncmp(senha2, senha, 6) == 0) {
      digitalWrite(5, HIGH); //ativar o sensor
      Serial.println("Senha correta!");
    } else {
      Serial.println("Senha incorreta!");
    }
    
    //resetar a matriz senha2 e a variável contador
    memset(senha2, 0, sizeof(senha2));
    i = 0;
  }
}
