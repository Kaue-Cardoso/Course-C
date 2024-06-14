#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o n�mero digitado pelo usu�rio
    int numero;

    // Solicita ao usu�rio que digite um n�mero de 1 a 7
    printf("Digite um n�mero de 1 a 7: ");

    // L� o n�mero digitado pelo usu�rio e o armazena na vari�vel 'numero'
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
            printf("3 corresponde a Ter�a-feira.\n");
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
            printf("7 corresponde a S�bado.\n");
            break;
        default:
            // Caso o n�mero digitado n�o esteja entre 1 e 7
            printf("N�mero inv�lido! Digite um n�mero de 1 a 7.\n");
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
