#include <stdio.h>

int main(){
    int linhas;
        printf("Informa a quat de caracteres: ");
        scanf("%d", &linhas);

        for (int i=linhas; i>=1; i--){
            for (int j = i; i <= i; j++){
                printf("*");
            }
            printf("\n");
        }
    }
/* barra invertida \*/