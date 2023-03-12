#include <stdio.h>

int main(){

    /*Imprisão de comentario de jogo com cabeçalho*/
    printf("------------------------------\n");
    printf("Bem vindo ao jogo de adiviação\n");
    printf("Você terá trés chances de acerta no jogo\n");
    printf("------------------------------\n");

    int numSecreto = 40;
    
    int chute;

    

    printf("Qual seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

        
    //simplificação da var. numSecreto e chute p/ ACERTO
    int acerto = (chute == numSecreto);

    if (acerto) {
        printf("Parabéns você acertou!\n");
    }
            
    else {
            
    //simplificação da var e opção chute > numSecreto p/ MAIOR
    int maior = (chute > numSecreto);

    if(maior){
        printf("Seu chete foi maior que número secreto\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto\n");
            } 
            
        }}