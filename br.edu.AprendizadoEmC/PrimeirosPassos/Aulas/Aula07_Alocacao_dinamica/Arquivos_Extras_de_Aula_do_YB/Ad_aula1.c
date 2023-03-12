#include <stdio.h>

int main(void){
    int x; //  dado que fica armazenado é de 4 bits
    double y; // dado que fica armazenado de 8 bits

    //Existe como controlar ou medir esses dados?
    /*- Existe uma maneira de calcularo tamanho  dessa aloção
    usando sizeof()*/

    printf("%li\n", sizeof(x));
    printf("%li\n", sizeof(y));

    return 0;
}