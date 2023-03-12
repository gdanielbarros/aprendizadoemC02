/*Author Daniel Alves*/
#include <stdio.h>

int main(void)

/*abrindo o bloco com 
{ - - - - - }*/ 
{
    int num1, num2, totalSoma, totalMult, totalDiv;

    printf('\nDigite número para op: ');
    scanf("%d", &num1);

    printf('\nDigite número para op: ');
    scanf("%d", &num2);

    /*Processamento*/
    totalSoma = num1 + num2;

    totalMult = num1 * num2;

    totalDiv = num1 / num2;

    printf("\nResultado da soma: %d\n", totalSoma);
    printf("\nResultado da multiplicação: %d\n",totalMult);
    printf("\nResultado da divisão: %d\n",totalDiv);

    return 0;
}