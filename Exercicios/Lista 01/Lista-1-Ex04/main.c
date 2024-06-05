#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome1[30],nome2[30],nome3[30],nome4[30],nome5[30];
    printf("Bem Vindo ao Lista Nome!\nDigite 5 Nomes em Sequencia\n");
    scanf("%s", &nome1);
    scanf("%s", &nome2);
    scanf("%s", &nome3);
    scanf("%s", &nome4);
    scanf("%s", &nome5);
    printf("Os nomes sao %s, %s, %s, %s, %s", nome1,nome2,nome3,nome4,nome5);
    return 0;
}
