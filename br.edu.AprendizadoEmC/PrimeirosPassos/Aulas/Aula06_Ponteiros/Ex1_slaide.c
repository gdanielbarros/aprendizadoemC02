#include <stdio.h>

int main(void){
    
    // exemplo de ponteiro 
    int *ponteiro;
    int num = 6;

    //armazenando end de numero no ponteiro
    ponteiro = &num;

    printf("%d \n", ponteiro); //endereço da variavel numero
    printf("%d \n", ponteiro); // não faz sentido imprimir ponteiro como int
}