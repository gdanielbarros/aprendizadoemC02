/*Escreva quatro instruções diferentes em C; cada uma
deve somar 1 à variável inteira x.*/
#include <stdio.h>

int main(void){

    int x= 0;
    int a, b, c, d;

    a = x + 1;
    b = x + x;
    c = 2 + a + x;
    d = 3 + a + b + c + x;

    printf("Teste de resultado: ");
    
    printf("Resultado > %d\n %d\n %d\n %d\n", a, b, c, d);
    }