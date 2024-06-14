#include <stdio.h>

int main() {
    // Declaração da variável que armazenará o caractere digitado pelo usuário
    char caractere;

    // Solicita ao usuário que digite um caractere
    printf("Digite um caractere: ");

    // Lê o caractere digitado pelo usuário e o armazena na variável 'caractere'
    scanf("%c", &caractere);

    // Estrutura switch-case para determinar se o caractere é uma vogal ou uma consoante
    switch (caractere) {
        // Verifica se o caractere é uma vogal maiúscula ou minúscula
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("O caractere '%c' é uma vogal.\n", caractere);
            break;
        default:
            // Se não for uma vogal, assume-se que é uma consoante
            printf("O caractere '%c' é uma consoante.\n", caractere);
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
