#include <stdio.h>
#include <stdlib.h>

int main(){

    int numMagico, palpite;
    numMagico = rand(); /*Gera número mágico*/
    
    printf("Advinhe o número mágico");
    scanf("%d", &palpite);

    if (palpite == numMagico){
        printf("Certon\n");
        printf("%d é o número mágico: \n", numMagico);

    }
    else if (palpite > numMagico){
        printf("Número errado, muito alto\n");
    }
    else printf("Número errado, muito baixo\n");

    return 0; 
}