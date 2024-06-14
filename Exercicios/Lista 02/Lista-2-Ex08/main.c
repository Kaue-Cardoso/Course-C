#include <stdio.h>

int main() {
    // Declara��o das vari�veis que armazenar�o a opera��o e os dois n�meros
    char operacao;
    float num1, num2, resultado;

    // Solicita ao usu�rio que digite o nome de uma opera��o aritm�tica
    printf("Digite uma opera��o aritm�tica (+, -, *, /): ");
    // L� o caractere digitado pelo usu�rio e o armazena na vari�vel 'operacao'
    scanf(" %c", &operacao);

    // Solicita ao usu�rio que digite os dois n�meros
    printf("Digite o primeiro n�mero: ");
    scanf("%f", &num1);

    printf("Digite o segundo n�mero: ");
    scanf("%f", &num2);

    // Estrutura switch-case para calcular o resultado da opera��o escolhida
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Divis�o por zero n�o � permitida.\n");
            }
            break;
        default:
            // Caso a opera��o digitada n�o seja uma das opera��es aritm�ticas v�lidas
            printf("Opera��o inv�lida! Digite uma opera��o v�lida (+, -, *, /).\n");
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
