#include <stdio.h>

int main() {
    // Declaração das variáveis que armazenarão a operação e os dois números
    char operacao;
    float num1, num2, resultado;

    // Solicita ao usuário que digite o nome de uma operação aritmética
    printf("Digite uma operação aritmética (+, -, *, /): ");
    // Lê o caractere digitado pelo usuário e o armazena na variável 'operacao'
    scanf(" %c", &operacao);

    // Solicita ao usuário que digite os dois números
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    // Estrutura switch-case para calcular o resultado da operação escolhida
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
                printf("Erro: Divisão por zero não é permitida.\n");
            }
            break;
        default:
            // Caso a operação digitada não seja uma das operações aritméticas válidas
            printf("Operação inválida! Digite uma operação válida (+, -, *, /).\n");
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
