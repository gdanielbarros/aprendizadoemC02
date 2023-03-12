#include <stdio.h>
#include <string.h>

void trocando(int *x, int *y){

    int tempo = *x;
    *x = *y;
    *y = tempo;
}

void trocaNova(int x, int y){
    // valor de tempo em X
    int tempo = x;
    x = y;
    y = tempo;
}

int main(){
    int a = 1, b = 2;

    trocaNova(a,b);
    printf("a = %d, b = %d\n", a, b);
    
    trocando(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}