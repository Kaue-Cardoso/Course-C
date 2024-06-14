#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o n�mero inteiro
    int numero;

    // Solicita ao usu�rio que digite um n�mero inteiro
    printf("Digite um n�mero inteiro: ");

    // L� o n�mero inteiro digitado pelo usu�rio e o armazena na vari�vel 'numero'
    scanf("%d", &numero);

    // Verifica se o n�mero � divis�vel por 3 e por 5 usando o operador de m�dulo
    if (numero % 3 == 0 && numero % 5 == 0) {
        // Se o resto da divis�o do n�mero por 3 e por 5 for igual a zero, o n�mero � divis�vel por ambos
        printf("O n�mero %d � divis�vel por 3 e por 5.\n", numero);
    } else {
        // Se o n�mero n�o for divis�vel por ambos
        printf("O n�mero %d n�o � divis�vel por 3 e por 5.\n", numero);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
