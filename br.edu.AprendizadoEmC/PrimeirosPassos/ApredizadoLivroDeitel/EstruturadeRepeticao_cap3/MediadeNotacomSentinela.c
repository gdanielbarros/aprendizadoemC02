#include <stdio.h>

int main(void){
    int contador, total;
    float media, nota;

    total = 0;
    contador = 0;

    printf("\ndigite -1 para finalizar o programa\nDigite nota:");
    scanf("%f", &nota);

    while (nota != -1)
    {
        total = total + nota;
        contador = contador + 1;

        printf("Digite a nota, -1 para finalizar: \n");
        scanf("%f", &nota);
    }
    
    if (contador != 0){
        media = (float) total / contador;

        printf("Média da turma é %.2f\n", media);
    }
    else{
        printf("Nenhuma nota foi informada\n");
    }

    return 0; /*Indica que programa finalizou com sucesso */
}   