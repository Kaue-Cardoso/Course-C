#include <stdio.h>

#define TAMANHO 5

int main()
{
    int vetor[TAMANHO];
    int i, j, min_idx, temp;

    // Ler os elementos do vetor
    printf("Digite %d elementos:\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++)
    {
        scanf("%d", &vetor[i]);
    }

    // Ordenação por seleção
    for (i = 0; i < TAMANHO - 1; i++)
    {
        // Inicializa min_idx com o índice atual
        min_idx = i;

        // Percorre o restante do vetor para encontrar o menor elemento
        for (j = i + 1; j < TAMANHO; j++)
        {
            // Se encontrar um elemento menor, atualiza min_idx
            if (vetor[j] < vetor[min_idx])
            {
                min_idx = j;
            }
        }

        // Se min_idx foi atualizado, troca os elementos
        if (min_idx != i)
        {
            // Guarda o valor do elemento atual em temp
            temp = vetor[i];

            // Substitui o elemento atual pelo menor elemento encontrado
            vetor[i] = vetor[min_idx];

            // Coloca o valor original do elemento atual na posição do menor elemento encontrado
            vetor[min_idx] = temp;
        }
    }

    // Imprimir o vetor ordenado
    printf("Vetor ordenado:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
