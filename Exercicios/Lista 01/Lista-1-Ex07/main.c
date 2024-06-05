#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome1[30],nome2[30],nome3[30],nome4[30];
    int idade1,idade2,idade3,idade4;
    char posicao1[30],posicao2[30],posicao3[30],posicao4[30];
    printf("IBGE da casa Passando\n Diga o nome de 4 pessoas que moram na casa, suas idades e sua posição Familia\n");
    printf("Primeira Pessoa\nNome: ");
    scanf("%s", &nome1);
    printf("\nIdade: ");
    scanf("%d", &idade1);
    printf("\nPosicao: ");
    scanf("%s", &posicao1);
    printf("Segunda Pessoa\nNome: ");
    scanf("%s", &nome2);
    printf("\nIdade: ");
    scanf("%d", &idade2);
    printf("\nPosicao: ");
    scanf("%s", &posicao2);
    printf("Terceira Pessoa\nNome: ");
    scanf("%s", &nome3);
    printf("\nIdade: ");
    scanf("%d", &idade3);
    printf("\nPosicao: ");
    scanf("%s", &posicao3);
    printf("Quarta Pessoa\nNome: ");
    scanf("%s", &nome4);
    printf("\nIdade: ");
    scanf("%d", &idade4);
    printf("\nPosicao: ");
    scanf("%s", &posicao4);
    printf("As Pessoas são: %s, %s, %s, %s\n", nome1,nome2,nome3,nome4);
    printf("Suas Idades são: %d, %d, %d, %d\n", idade1,idade2,idade3,idade4);
    printf("Suas Posicoes: %s, %s, %s, %s\n", posicao1,posicao2,posicao3,posicao4);
    return 0;
}
