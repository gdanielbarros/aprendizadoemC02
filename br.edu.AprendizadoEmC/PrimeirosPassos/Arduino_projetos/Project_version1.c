/*Authores	 	Daniel Alves de Barros (principal) 
				Kaelany dos Santos Soares 
				Marcelo de Oliveira Barbosa 
				Carlle Oliveira*/

//pinos para os leds e teclado
const int ledVermelho = 2;
const int ledVerde = 3;
const int tecladoPino = 4;

// a senha
const String senha = "1234";

//variáveis para armazenar a senha digitada e o índice atual
String senhaDigitada = "";
int indiceSenha = 0;

// variável para armazenar se o alarme está ativado
bool alarmeAtivado = false;

//configurar os pinos dos LEDs e teclado
void setup() {
  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(tecladoPino, INPUT);
  
  //iniciar o monitor serial para depuração
  Serial.begin(9600);
}

void loop() {
  //Verificar se o alarme está ativado
  if (alarmeAtivado) {
    //Ligada o LED vermelho se o alarme está ativado
    digitalWrite(ledVermelho, HIGH);
  } else {
    // E Desligado o LED vermelho se o alarme está desativado
    digitalWrite(ledVermelho, LOW);
  }
  
  // ler o teclado e adicionar o caractere digitado à senha digitada
  char tecla = lerTeclado();
  if (tecla != 0) {
    senhaDigitada += tecla;
    Serial.println(senhaDigitada);
    
    // verificar se a senha digitada é igual à senha definida
    if (senhaDigitada == senha) {
      Serial.println("Senha correta!");
      // ligado o LED verde se a senha está correta
      digitalWrite(ledVerde, HIGH);
      delay(1000);
      digitalWrite(ledVerde, LOW);
      
      // resetar a senha digitada e o índice
      senhaDigitada = "";
      indiceSenha = 0;
    } else {
      // o índice da senha
      indiceSenha++;
      
      // verificar se a senha está incorreta há 3 tentativas
      if (indiceSenha >= 3) {
        Serial.println("Senha incorreta! Ativando o alarme.");
        // ativar o alarme se a senha está incorreta 3 vezes
        alarmeAtivado = true;
        
        // resetar a senha digitada e o índice
        senhaDigitada = "";
        indiceSenha = 0;
      }
    }
  }
}

// ler o teclado e retornar o caractere digitado
char lerTeclado() {
  char tecla = 0;
  
  // verificar se há uma tecla pressionada
  if (digitalRead(tecladoPino) == HIGH) {
    // Esperar a tecla ser liberada
    while (digitalRead(tecladoPino) == HIGH) {}
    
    // obter o valor da tecla pressionada
    int valorTecla = analogRead(tecladoPino);
    
    // mapear o valor da tecla para o caractere correspondente
    if (valorTecla > 900 && valorTecla < 950) {
      tecla = '1';
    } else if (valorTecla > 750 && valorTe
