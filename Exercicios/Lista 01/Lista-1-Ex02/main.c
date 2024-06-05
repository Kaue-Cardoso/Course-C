#include <stdio.h>
#include <stdlib.h>

int main()
{
    float raio;
    printf("Bem Vindo ao Calculador de Area\nDigite o valor do Raio do Circulo: ");
    scanf("%f", &raio);
    printf("A area do circulo e: %0.1f", 3.14*(raio*raio));
    return 0;
}
