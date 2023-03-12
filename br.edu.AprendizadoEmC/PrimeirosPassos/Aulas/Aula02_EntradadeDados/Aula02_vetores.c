#include <stdio.h>
#include <string.h>

int main() {

    char s1[10], s2[10];

    gets(s1);
    gets(s2);

    if (strcmp(s1, s2)== 0)
    printf("\nStrings iguais");

    strcat(s1, s2);
    puts(s1);
    return 0;
}