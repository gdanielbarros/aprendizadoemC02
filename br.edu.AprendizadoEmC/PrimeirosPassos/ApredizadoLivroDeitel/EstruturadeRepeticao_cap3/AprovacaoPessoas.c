/* link para acessar mais informações sobre loop
https://www.facom.ufu.br/~backes/gsi002/Aula05-ComandosRepeticao.pdf*/

#include <stdio.h>
int main(void){

    int valor, contador;

    valor = 1;

    for (contador = 1; contador < 5; contador = contador + 1)
    {
        printf("Digite o numero");
        scanf("%d", &contador);
    }
    

    /*while (valor <= 3)
    {
        printf("Digite o valor:\n");
        scanf("%d", &valor);
        valor = valor + 1;
        soma = valor + valor;

    }*/
    
    
return 0;
}