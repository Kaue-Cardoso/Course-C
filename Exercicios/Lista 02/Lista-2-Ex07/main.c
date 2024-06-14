#include <stdio.h>

int main() {
    // Declara��o da vari�vel que armazenar� o caractere digitado pelo usu�rio
    char caractere;

    // Solicita ao usu�rio que digite um caractere
    printf("Digite um caractere: ");

    // L� o caractere digitado pelo usu�rio e o armazena na vari�vel 'caractere'
    scanf("%c", &caractere);

    // Estrutura switch-case para determinar se o caractere � uma vogal ou uma consoante
    switch (caractere) {
        // Verifica se o caractere � uma vogal mai�scula ou min�scula
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
            printf("O caractere '%c' � uma vogal.\n", caractere);
            break;
        default:
            // Se n�o for uma vogal, assume-se que � uma consoante
            printf("O caractere '%c' � uma consoante.\n", caractere);
            break;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
