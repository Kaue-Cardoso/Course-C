#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o número digitado pelo usuário
    int numero;

    // Solicita ao usuário que digite um número de 1 a 7
    printf("Digite um número de 1 a 7: ");

    // Lê o número digitado pelo usuário e o armazena na variável 'numero'
    scanf("%d", &numero);

    // Estrutura switch-case para determinar o dia da semana correspondente
    switch (numero) {
        case 1:
            printf("1 corresponde a Domingo.\n");
            break;
        case 2:
            printf("2 corresponde a Segunda-feira.\n");
            break;
        case 3:
            printf("3 corresponde a Terça-feira.\n");
            break;
        case 4:
            printf("4 corresponde a Quarta-feira.\n");
            break;
        case 5:
            printf("5 corresponde a Quinta-feira.\n");
            break;
        case 6:
            printf("6 corresponde a Sexta-feira.\n");
            break;
        case 7:
            printf("7 corresponde a Sábado.\n");
            break;
        default:
            // Caso o número digitado não esteja entre 1 e 7
            printf("Número inválido! Digite um número de 1 a 7.\n");
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
