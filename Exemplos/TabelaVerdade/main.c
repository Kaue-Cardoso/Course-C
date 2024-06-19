#include <stdio.h> // Biblioteca padrão de entrada e saída

int main() {
    int A, B; // Declaração de variáveis para armazenar os valores fornecidos pelo usuário

    // Exibe a tabela verdade
    printf("Tabela Verdade\n");
    printf("A | B | A AND B | A OR B | NOT A | NOT B\n");
    printf("----------------------------------------\n");
    printf("0 | 0 |    0    |    0   |   1   |   1   \n");
    printf("0 | 1 |    0    |    1   |   1   |   0   \n");
    printf("1 | 0 |    0    |    1   |   0   |   1   \n");
    printf("1 | 1 |    1    |    1   |   0   |   0   \n");

    // Solicita ao usuário para digitar dois valores booleanos (0 ou 1)
    printf("\nDigite o valor de A (0 ou 1): ");
    scanf("%d", &A); // Lê o valor digitado pelo usuário e armazena na variável 'A'

    printf("Digite o valor de B (0 ou 1): ");
    scanf("%d", &B); // Lê o valor digitado pelo usuário e armazena na variável 'B'

    // Verifica se os valores fornecidos são válidos (0 ou 1)
    if ((A == 0 || A == 1) && (B == 0 || B == 1)) {
        // Exibe os resultados das operações lógicas
        printf("\nResultados das operações lógicas:\n");

        // A AND B
        if (A && B)
            printf("A AND B: 1 (Verdadeiro)\n");
        else
            printf("A AND B: 0 (Falso)\n");

        // A OR B
        if (A || B)
            printf("A OR B: 1 (Verdadeiro)\n");
        else
            printf("A OR B: 0 (Falso)\n");

        // NOT A
        if (!A)
            printf("NOT A: 1 (Verdadeiro)\n");
        else
            printf("NOT A: 0 (Falso)\n");

        // NOT B
        if (!B)
            printf("NOT B: 1 (Verdadeiro)\n");
        else
            printf("NOT B: 0 (Falso)\n");
    } else {
        // Exibe uma mensagem de erro se os valores fornecidos não são válidos
        printf("Valores inválidos. Por favor, digite 0 ou 1.\n");
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
