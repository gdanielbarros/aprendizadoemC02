#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 5

int main(){

    /*Imprisão de comentario de jogo com cabeçalho*/
    printf("------------------------------\n");
    printf("Bem vindo ao jogo de adiviação\n");
    printf("Você terá trés chances de acerta no jogo\n");
    printf("------------------------------\n");

    int numSecreto = 40;
    
    int chute;

    // Versão com loop 
    for (int indice = 1; indice <= NUMERO_DE_TENTATIVAS; indice++){

        printf("Tentativa %d de 5\n\n", indice, NUMERO_DE_TENTATIVAS);
        printf("Qual seu chute?\n");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        //simplificação da var. numSecreto e chute p/ ACERTO
        int acertou = (chute == numSecreto);

        if (acertou) {
            printf("Parabéns você acertou!\n");
            printf("\nFIM DE JOGO\n");
            break;
           
        }  
        else {
            //simplificação da var e opção chute > numSecreto p/ MAIOR
            int maior = (chute > numSecreto);

            if(maior){
                printf("Jogue de novo, você é um bom jogador!\n");
                printf("Seu chute foi maior que número secreto\n");
            }
            else {
                printf("Jogue de novo, você é um bom jogador!\n");
                printf("Seu chute foi menor que número secreto\n");
            }  
        }
    }
}