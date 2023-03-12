#include <stdio.h>
/**/
int quadrado(int x)
{

    return x * x;
    //exemplo: o que esta após retono não é executado
    printf("Isso não é impresso :(");

}

int main(){
    printf("Quadrado de  2 é %d\n", quadrado(2));
    printf("\nAqui é fim do programa");


    return 0;
}    
