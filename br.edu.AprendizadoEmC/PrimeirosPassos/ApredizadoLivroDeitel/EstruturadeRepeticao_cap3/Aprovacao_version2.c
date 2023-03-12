#include <stdio.h>
int main(void){
    int aprovados = 0, reprovados = 0, contador = 0, notaCondicao;


    while (contador <= 4)
    {
        printf("Digite 1 > APROVADO - 2 > REPROVADO\n");
        printf("\nDigite o resultado teste:\n");
        scanf("%d", &notaCondicao);
        
        if (notaCondicao == 1){
            aprovados ++;
        }
        else if (notaCondicao == 2)
        {
            reprovados ++;
        }
        else{
            printf("Valor é invalido. Aceita apenas 1 ou 2\n");
        }
        contador ++;
    }

    /*OBS.: Na segunda edição, coloca 
        se tiver apenas 1 aprovado coloca no singular
        se tiver apenas 1 reprocado também imprimir assim*/ 
    printf("Resultados: %d aprovados e %d reprovados\n", aprovados, reprovados);

    if (aprovados > 2){
        printf("Bonus para o instrutor\n");
    }
    
    return 0;
}