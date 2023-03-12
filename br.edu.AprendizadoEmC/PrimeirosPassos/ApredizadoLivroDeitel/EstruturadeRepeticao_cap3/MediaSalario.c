/*Baseado num exemplo do livo feito com notas, irei fazer um pg de média salarial*/
/// Author: Daniel

#include <stdio.h>

int main(){

float salario, TotalMedia, media; //salrio e soma da média total
int contador; //Cotador de repetição

contador = 1; 

//Avisa ao usuario apenas uma vez
printf("\nVocê vai digita o salario de cada funcionario 10 vezes. \n");

while (contador <= 10)
{
    printf("\nValor do salario: ");
    scanf("%f", &salario);
    TotalMedia = salario + TotalMedia;
    contador = contador + 1;
}

media = TotalMedia / 10;

printf("Média salario da empresa é: %f", media);
}