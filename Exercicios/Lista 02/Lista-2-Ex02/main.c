#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o número inteiro
    int numero;

    // Solicita ao usuário que digite um número inteiro
    printf("Digite um número inteiro: ");

    // Lê o número inteiro digitado pelo usuário e o armazena na variável 'numero'
    scanf("%d", &numero);

    // Verifica se o número é par ou ímpar usando o operador de módulo
    if (numero % 2 == 0) {
        // Se o resto da divisão do número por 2 for igual a zero, o número é par
        printf("O número %d é par.\n", numero);
    } else {
        // Se o resto da divisão do número por 2 não for igual a zero, o número é ímpar
        printf("O número %d é ímpar.\n", numero);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
