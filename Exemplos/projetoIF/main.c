#include <stdio.h> //

int main() {
    int num; // Declaração de uma variável inteira para armazenar o número do usuário

    // Solicita ao usuário para digitar um número
    printf("Digite um numero: ");
    scanf("%d", &num); // Lê o número digitado pelo usuário e armazena na variável 'num'

    // Estrutura condicional 'if' para verificar se o número é positivo
    if (num > 0) {
        // Se a condição (num > 0) for verdadeira, este bloco de código será executado
        printf("O numero %d e positivo.\n", num); // Imprime que o número é positivo
    }
    // Estrutura condicional 'else if' para verificar se o número é negativo
    else if (num < 0) {
        // Se a condição (num < 0) for verdadeira, este bloco de código será executado
        printf("O numero %d e negativo.\n", num); // Imprime que o número é negativo
    }
    // Estrutura condicional 'else' para o caso em que o número é zero
    else {
        // Se nenhuma das condições anteriores for verdadeira, este bloco de código será executado
        printf("O numero e zero.\n"); // Imprime que o número é zero
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
