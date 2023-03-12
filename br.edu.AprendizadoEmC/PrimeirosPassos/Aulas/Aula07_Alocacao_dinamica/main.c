//simulando entreada com nome/string
#include <stdio.h>

int main(void){
    char nome1[20], nome2[21];
    
    printf("Primeiro nome:\n");
    scanf("%s", nome1);

    printf("segundo nome:\n");
    scanf("%s", nome2);

    printf("Ola senhor %s, %s. Bem-vindo\n", nome1, nome2);

    return 0;
    }