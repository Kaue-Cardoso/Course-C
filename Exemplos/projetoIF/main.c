#include <stdio.h> //

int main() {
    int num; // Declara��o de uma vari�vel inteira para armazenar o n�mero do usu�rio

    // Solicita ao usu�rio para digitar um n�mero
    printf("Digite um numero: ");
    scanf("%d", &num); // L� o n�mero digitado pelo usu�rio e armazena na vari�vel 'num'

    // Estrutura condicional 'if' para verificar se o n�mero � positivo
    if (num > 0) {
        // Se a condi��o (num > 0) for verdadeira, este bloco de c�digo ser� executado
        printf("O numero %d e positivo.\n", num); // Imprime que o n�mero � positivo
    }
    // Estrutura condicional 'else if' para verificar se o n�mero � negativo
    else if (num < 0) {
        // Se a condi��o (num < 0) for verdadeira, este bloco de c�digo ser� executado
        printf("O numero %d e negativo.\n", num); // Imprime que o n�mero � negativo
    }
    // Estrutura condicional 'else' para o caso em que o n�mero � zero
    else {
        // Se nenhuma das condi��es anteriores for verdadeira, este bloco de c�digo ser� executado
        printf("O numero e zero.\n"); // Imprime que o n�mero � zero
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
