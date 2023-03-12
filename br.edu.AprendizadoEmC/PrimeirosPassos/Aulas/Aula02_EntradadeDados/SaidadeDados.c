#include <stdio.h>

void main(void){
    int indice;

    /*Mostra toda uma tabela de números quadrados*/
    for (indice = 1; indice < 20; indice++){
        printf("%8d %8d\n", indice, indice*indice, indice*indice*indice);
    }
}