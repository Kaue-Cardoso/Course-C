#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[10] = " saudacao";
    int tamanho = strlen(palavra);           // Obtém o comprimento da string

    // Ajusta o tamanho do array copia para ser grande o suficiente
    char copia[20];
    strcpy(copia, palavra);                  // Copia uma string para outra
    strcat(copia, palavra);                 // Concatena duas strings

    int resultado = strcmp(copia,palavra );  // Compara duas strings
    /* Um valor negativo se a primeira string for menor que a segunda.
       Zero se as duas strings forem iguais.
       Um valor positivo se a primeira string for maior que a segunda.
    */

    // Exibe os resultados
    printf("Palavra escolhida: %s\n", palavra);
    printf("Tamanho da palavra: %d\n", tamanho);
    printf("Var Copia: %s\n", copia);
    printf("Resultado da comparacao: %d\n", resultado);

    return 0;
}
