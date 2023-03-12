/*Jogo advinhando numero mágico (usando op. ternário - Versão 2)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numMagico, palpite;
    numMagico = rand(); /*Gera número mágico*/
    
    printf("Advinhe o número mágico: \n");
    scanf("%d", &palpite);

    if (palpite == numMagico){
        printf("Certon\n");
        printf("%d é o número mágico: \n", numMagico);

    }
    else if (palpite > numMagico){
        printf("Número errado, muito alto\n");
        printf(palpite > numMagico ? "valor alto!" : "Valor muito baixo!");
    }
    
    printf("\nO número era %d", numMagico);

    return 0; 
}