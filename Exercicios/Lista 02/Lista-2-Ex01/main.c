#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o número inteiro
    int numero;

    // Solicita ao usuário que digite um número inteiro
    printf("Digite um número inteiro: ");

    // Lê o número inteiro digitado pelo usuário e o armazena na variável 'numero'
    scanf("%d", &numero);

    // Verifica se o número é positivo, negativo ou zero
    if (numero > 0) {
        // Caso o número seja maior que zero, ele é positivo
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        // Caso o número seja menor que zero, ele é negativo
        printf("O número %d é negativo.\n", numero);
    } else {
        // Caso o número seja igual a zero
        printf("O número é zero.\n");
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
