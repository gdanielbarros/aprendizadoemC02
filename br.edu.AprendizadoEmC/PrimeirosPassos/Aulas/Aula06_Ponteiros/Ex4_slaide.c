#include <stdio.h>

int main(void){
    int numero;
    char nome[40];

    scanf("%d", &numero);

    gets(nome);

    printf("n numero: %d\n", numero);
    printf("nome: %s\n", numero);
}