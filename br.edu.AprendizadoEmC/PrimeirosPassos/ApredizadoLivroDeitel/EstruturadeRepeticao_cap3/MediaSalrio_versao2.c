/*######################################################################################
Baseado num exemplo do livo feito com notas, irei fazer um pg de média salarial

prt 2-  Nessa outra versão de acordo com orientação do livro, vou implmenta um codigo com
        repetição infinita parando após ser acionado uma "chave" que chamada de 
########################################################################################
/// Author: Daniel
*/

#include <stdio.h>

int main(){

float salario, total = 0, media, totaldaMedia; //salrio e soma da média total
int contador = 0; //Cotador de repetição


//Avisa ao usuario apenas uma vez
printf("\nVocê vai digita salario de cada um\n*A T E N Ç Ã O - Pra encerra digite -1 \n");

while (contador >= 1)
{
    printf("\nValor do salario: ");
    scanf("%f", &salario); 
    total = salario + contador;
    contador = contador + 1;
}

totaldaMedia = total / contador;

printf("Média salario da empresa é: %f", media);
}