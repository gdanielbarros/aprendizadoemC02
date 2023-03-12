/*Unidade academica de Caruaru - UPE Caruaru
        AUTHOR: Daniel Alves de Lima B. M.*/

int LedLuz = 2;
int espera = 200, esperaLonge = 500, esperaGrande = 1000;

void setup(){
    pinMode(LedLuz, OUTPUT);
}

void loop(){

    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(espera);

    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(espera);


    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(esperaGrande);

    //O  
    digitalWrite(LED, HIGH);
    delay(esperaGrande);
    digitalWrite(LED, LOW);
    delay(espera);
    
    digitalWrite(LED, HIGH);
    delay(esperaGrande);
    digitalWrite(LED, LOW);
    delay(espera);
    
    digitalWrite(LED, HIGH);
    delay(esperaGrande);
    digitalWrite(LED, LOW);
    delay(esperaGrande);

    //s
    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(espera);

    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(espera);

    digitalWrite(LED, HIGH);
    delay(espera);
    digitalWrite(LED, LOW);
    delay(esperaGrande);

    delay(esperaGrande);
}