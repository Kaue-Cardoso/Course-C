#include <stdio.h>

int main() {
    int numero;

    // Solicita ao usuário que insira um número positivo
    do {
        printf("Insira um número: ");
        scanf("%d", &numero);
    } while (numero != 0); // Continua solicitando até que um número positivo seja inserido

    printf("O número inserido é: %d\n", numero);

    return 0;
}
