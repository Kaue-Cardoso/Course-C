#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o ano
    int ano;

    // Solicita ao usuário que digite um ano
    printf("Digite um ano: ");

    // Lê o ano digitado pelo usuário e o armazena na variável 'ano'
    scanf("%d", &ano);

    // Verifica se o ano é bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        // Se o ano é divisível por 4 e não é divisível por 100, ou se é divisível por 400
        printf("O ano %d é bissexto.\n", ano);
    } else {
        // Caso contrário, o ano não é bissexto
        printf("O ano %d não é bissexto.\n", ano);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
