#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o número inteiro
    int numero;

    // Solicita ao usuário que digite um número inteiro
    printf("Digite um número inteiro: ");

    // Lê o número inteiro digitado pelo usuário e o armazena na variável 'numero'
    scanf("%d", &numero);

    // Verifica se o número é múltiplo de 5 usando o operador de módulo
    if (numero % 5 == 0) {
        // Se o resto da divisão do número por 5 for igual a zero, o número é múltiplo de 5
        printf("O número %d é múltiplo de 5.\n", numero);
    } else {
        // Se o resto da divisão do número por 5 não for igual a zero, o número não é múltiplo de 5
        printf("O número %d não é múltiplo de 5.\n", numero);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
