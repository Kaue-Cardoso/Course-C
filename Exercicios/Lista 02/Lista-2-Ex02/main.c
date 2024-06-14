#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o n�mero inteiro
    int numero;

    // Solicita ao usu�rio que digite um n�mero inteiro
    printf("Digite um n�mero inteiro: ");

    // L� o n�mero inteiro digitado pelo usu�rio e o armazena na vari�vel 'numero'
    scanf("%d", &numero);

    // Verifica se o n�mero � par ou �mpar usando o operador de m�dulo
    if (numero % 2 == 0) {
        // Se o resto da divis�o do n�mero por 2 for igual a zero, o n�mero � par
        printf("O n�mero %d � par.\n", numero);
    } else {
        // Se o resto da divis�o do n�mero por 2 n�o for igual a zero, o n�mero � �mpar
        printf("O n�mero %d � �mpar.\n", numero);
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
