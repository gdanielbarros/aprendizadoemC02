#include <stdio.h>
#include <string.h>

int main(int *d1, int *d2){
    int tempo;
    tempo = *d1; // passando referencia?

    // apontamento
    *d1 = *d2;
    *d2 = tempo;

}
void trocaB(int d1, int d2){
    int tempo = d1;
    d1 = d2;
    d2 = tempo;
}
// outra operação com outra função
void main(){
    int a = 1, b = 2;

    trocaB(a, b);
    printf("A = %d, B = %d\n", a, b);
    
    troca(&a, &b);
    printf("A = %d, B = %d", a, b);

    return 0;
}