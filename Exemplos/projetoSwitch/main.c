#include <stdio.h> //

int main() {
    int num; // Declara��o de uma vari�vel inteira para armazenar o n�mero do usu�rio

    // Solicita ao usu�rio para digitar um n�mero
    printf("Digite um n�mero: ");
    scanf("%d", &num); // L� o n�mero digitado pelo usu�rio e armazena na vari�vel 'num'

    // Utiliza 'switch' para determinar a categoria do n�mero
    switch ((num > 0) - (num < 0)) { // Avalia as condi��es e calcula o valor da express�o
        case 1:
            // Se a express�o resulta em 1, o n�mero � positivo
            printf("O n�mero %d � positivo.\n", num);
            break;
        case -1:
            // Se a express�o resulta em -1, o n�mero � negativo
            printf("O n�mero %d � negativo.\n", num);
            break;
        case 0:
            // Se a express�o resulta em 0, o n�mero � zero
            printf("O n�mero � zero.\n");
            break;
        default:
            // Caso padr�o (n�o deve ocorrer neste exemplo)
            printf("Erro inesperado.\n");
            break;
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
