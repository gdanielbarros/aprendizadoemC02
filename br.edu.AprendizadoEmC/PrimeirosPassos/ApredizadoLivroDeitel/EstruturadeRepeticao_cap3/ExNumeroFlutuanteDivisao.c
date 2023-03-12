#include <stdio.h>
int main(int)
{
    /*Variavel*/
    float num1, num2;

    printf("Primeiro número: \n");
    scanf("%f", &num1);

    printf("Número do divisor: \n");
    scanf("%f", &num2);

    //processamento 
    float soma = num1 / num2;

    printf("Valor da divisão é: %f\n", soma);
    printf("Valor da divisão arendodado é: %.2f\n", soma);
    return 0;
}
