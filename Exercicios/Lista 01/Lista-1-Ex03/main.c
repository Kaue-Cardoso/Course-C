#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp, temp1;
    printf("Manda a Temperatura: \n");
    scanf("%f", &temp);
    printf("A temperatura em Fahrenheit e: %0.1f", temp*(9/5.0)+32); //Para o calculo dar certo, devemos fazer o casting do tipo calculado
    return 0;
}
