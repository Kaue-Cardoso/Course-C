#include <stdio.h>

int main() {
    int numero; // Variável para armazenar o número fornecido pelo usuário
    int soma; // Variável para armazenar a soma dos números

    // Exibe uma mensagem inicial explicando o funcionamento do programa
    printf("Este programa soma números fornecidos pelo usuário.\n");
    printf("Digite 0 para terminar e exibir a soma total.\n\n");

    // Solicita ao usuário para digitar o primeiro número
    printf("Digite um número: ");
    scanf("%d", &numero); // Lê o número digitado pelo usuário

    // Loop while: continuará executando enquanto 'numero' for diferente de 0
    while (numero != 0) {
        soma += numero; // Adiciona o número fornecido à variável 'soma'

        // Solicita ao usuário para digitar o próximo número
        printf("Digite outro número (ou 0 para terminar): ");
        scanf("%d", &numero); // Lê o próximo número digitado pelo usuário
    }

    // Exibe a soma total dos números fornecidos
    printf("\nA soma total é: %d\n", soma);

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}




