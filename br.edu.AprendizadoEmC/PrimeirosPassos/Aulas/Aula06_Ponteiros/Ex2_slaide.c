#include <stdio.h>

int main(void){

    float num = 10.5, num2;

    int *p;

    p = &num;

    num2 = *p;

    printf("%f\n", num2);
}   