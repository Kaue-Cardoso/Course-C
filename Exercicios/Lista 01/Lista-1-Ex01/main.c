#include <stdio.h>
#include <stdlib.h>

int main()
{   int num1,num2;
    printf("Seja Bem Vindo ao Calculador!!\nInsira o primeiro valor: ");
    scanf("%d",&num1);
    printf("Insira o Segundo valor: ");
    scanf("%d",&num2);
    printf("Resultado dos Operacoes \n");
    printf("Soma: %d \nSubtracao: %d \nMultiplicacao: %d \nDivisao: %d \n", num1+num2, num1-num2, num1*num2, num1/num2);
    return 0;
}
