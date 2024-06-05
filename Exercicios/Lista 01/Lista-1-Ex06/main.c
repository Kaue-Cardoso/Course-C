#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota1, nota2, nota3, nota4;
    printf("BOLETIM\n");
    printf("Insira a Primeira nota: ");
    scanf("%d", &nota1);
    printf("Insira a Segunda nota: ");
    scanf("%d", &nota2);
    printf("Insira a Terceira nota: ");
    scanf("%d", &nota3);
    printf("Insira a Quarta nota: ");
    scanf("%d", &nota4);
    printf("A média das notas é: %d", (nota1+nota2+nota3+nota4)/4 );

    return 0;
}
