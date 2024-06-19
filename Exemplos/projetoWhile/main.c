#include <stdio.h>

int main() {
    int numero; // Vari�vel para armazenar o n�mero fornecido pelo usu�rio
    int soma; // Vari�vel para armazenar a soma dos n�meros

    // Exibe uma mensagem inicial explicando o funcionamento do programa
    printf("Este programa soma n�meros fornecidos pelo usu�rio.\n");
    printf("Digite 0 para terminar e exibir a soma total.\n\n");

    // Solicita ao usu�rio para digitar o primeiro n�mero
    printf("Digite um n�mero: ");
    scanf("%d", &numero); // L� o n�mero digitado pelo usu�rio

    // Loop while: continuar� executando enquanto 'numero' for diferente de 0
    while (numero != 0) {
        soma += numero; // Adiciona o n�mero fornecido � vari�vel 'soma'

        // Solicita ao usu�rio para digitar o pr�ximo n�mero
        printf("Digite outro n�mero (ou 0 para terminar): ");
        scanf("%d", &numero); // L� o pr�ximo n�mero digitado pelo usu�rio
    }

    // Exibe a soma total dos n�meros fornecidos
    printf("\nA soma total �: %d\n", soma);

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}




