#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o n�mero inteiro
    int numero;

    // Solicita ao usu�rio que digite um n�mero inteiro
    printf("Digite um n�mero inteiro: ");

    // L� o n�mero inteiro digitado pelo usu�rio e o armazena na vari�vel 'numero'
    scanf("%d", &numero);

    // Verifica se o n�mero � positivo, negativo ou zero
    if (numero > 0) {
        // Caso o n�mero seja maior que zero, ele � positivo
        printf("O n�mero %d � positivo.\n", numero);
    } else if (numero < 0) {
        // Caso o n�mero seja menor que zero, ele � negativo
        printf("O n�mero %d � negativo.\n", numero);
    } else {
        // Caso o n�mero seja igual a zero
        printf("O n�mero � zero.\n");
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
