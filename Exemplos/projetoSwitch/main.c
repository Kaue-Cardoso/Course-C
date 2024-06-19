#include <stdio.h> //

int main() {
    int num; // Declaração de uma variável inteira para armazenar o número do usuário

    // Solicita ao usuário para digitar um número
    printf("Digite um número: ");
    scanf("%d", &num); // Lê o número digitado pelo usuário e armazena na variável 'num'

    // Utiliza 'switch' para determinar a categoria do número
    switch ((num > 0) - (num < 0)) { // Avalia as condições e calcula o valor da expressão
        case 1:
            // Se a expressão resulta em 1, o número é positivo
            printf("O número %d é positivo.\n", num);
            break;
        case -1:
            // Se a expressão resulta em -1, o número é negativo
            printf("O número %d é negativo.\n", num);
            break;
        case 0:
            // Se a expressão resulta em 0, o número é zero
            printf("O número é zero.\n");
            break;
        default:
            // Caso padrão (não deve ocorrer neste exemplo)
            printf("Erro inesperado.\n");
            break;
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
