/*Programa com soma e entrada de usuario
Author: Daniel Alves Barros*/
#include <stdio.h>

int main(void) 
{
    int num1, num2, soma; /* entrada 1 infor. pelo usuario*/


    printf("\nPrimeiro número inteiro: "); /*Primeira entrada*/
    scanf("%d", &num1);

    printf("\nDigite segundo numero: ");
    scanf("%d", &num2); /*Segunda entrada*/

    /*Processamento de conta*/
    soma = num1 + num2; /*Somando conta*/

    printf("\nA soma é %d\n", soma); /*Imprimindo a soma*/

    return 0;
}