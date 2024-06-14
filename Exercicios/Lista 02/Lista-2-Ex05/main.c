#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o ano
    int ano;

    // Solicita ao usu�rio que digite um ano
    printf("Digite um ano: ");

    // L� o ano digitado pelo usu�rio e o armazena na vari�vel 'ano'
    scanf("%d", &ano);

    // Verifica se o ano � bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        // Se o ano � divis�vel por 4 e n�o � divis�vel por 100, ou se � divis�vel por 400
        printf("O ano %d � bissexto.\n", ano);
    } else {
        // Caso contr�rio, o ano n�o � bissexto
        printf("O ano %d n�o � bissexto.\n", ano);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
