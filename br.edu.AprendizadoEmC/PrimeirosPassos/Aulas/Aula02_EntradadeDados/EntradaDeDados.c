*/*Nesse exeplo será usada entrada de dados com int, char (que letras/strings) e ponto flutuante*/
#include <stdio.h>

int main() {

    /*Programa apresenta um eero inesperado*/

    int inteiro;
    char letra;
    float num;
    int linha, coluna;

    scanf("%d %c %f", &inteiro, &letra, &num);
    
    printf("%d %c %f", inteiro, letra, num);
    
    
    printf("\nDigite a casa para atacar no formato de linha, coluna: ");
    scanf("%d, %d", &linha, &coluna);


    printf("\nCasa escolhida: [%d, %d]", linha, coluna);

    return 0;
}