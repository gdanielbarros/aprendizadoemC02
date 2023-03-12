/*Author Daniel Alves de Barros*/

/*Exemplo de programa dado livro de C do Deitel usando condição if*/
#include <stdio.h>

int main(void){
    float num1, num2, totalNota;

    printf("\nDigite a primeira nota: ");
    scanf("%e", &num1);

    printf("\nDigite a segunda nota: ");
    scanf("%e", &num2);

    //Soma dos numeros e condição
    totalNota = num1 + num2; 

    //condição de entrada
    if (totalNota >= 60){
        printf("Aprovado\n");
    }
    else{
        printf("Reprovado por falta de média\n");
    }
}