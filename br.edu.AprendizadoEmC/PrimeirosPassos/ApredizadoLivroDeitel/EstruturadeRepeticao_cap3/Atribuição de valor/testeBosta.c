#include <stdio.h>
#include <stdlib.h>

int main(void){
    int var1;

    var1 = 2;

    //var2 = 1;
     

    printf("\nResuldado sem  %d", var1);
    printf("\nResuldado com ++  %d", var1++);
    printf("\nResuldado com  -- (antes) %d", --var1);
    printf("\nResuldado com --(depois)  %d", var1--);
    printf("\nResuldado com += %d", +var1);
    printf("\nResuldado com =+ %d", -+var1);




    return 0;
}