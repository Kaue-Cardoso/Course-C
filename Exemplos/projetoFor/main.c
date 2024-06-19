#include <stdio.h>

int main() {
    int numero;
int vezes;
    // Solicita ao usuário para digitar um número
    printf("Digite um número para exibir a sua tabuada: ");
    scanf("%d", &numero); // Lê o número digitado pelo usuário

    // Exibe a tabuada do número fornecido
    printf("Tabuada do %d:\n", numero);
    for (int i = 1; i <= 10; i++) {

        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}


// for( variavel que será contada; Contagem; incremento )







