#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Declaração: Um array em C é declarado especificando o tipo de seus elementos e o número de elementos que ele conterá. Por exemplo:
    int numeros[10];

    Inicialização explícita:
    int numeros[5] = {1, 2, 3, 4, 5};
    Inicialização implícita:
    int numeros[] = {1, 2, 3, 4, 5};
    */
    int numeros[] = {1, 2, 3, 4, 5}, valor;
    printf("Seja Bem Vindo ao Sistema\nNumeros Dentro do Array ");
    for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]);
    }
    valor = numeros[2];  // Acessa o terceiro elemento do array
    printf("\nValor do terceiro campo do vetor atual: %d", valor);
    printf("\nDigite um novo valor para o terceiro campo: ");
    scanf("%d", &valor );
    numeros[2] = valor;  // Acessa o terceiro elemento do array
    for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]);
    }

    return 0;
}
