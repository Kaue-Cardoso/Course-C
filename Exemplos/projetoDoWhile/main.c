#include <stdio.h>

int main() {
    int numero;

    // Solicita ao usu�rio que insira um n�mero positivo
    do {
        printf("Insira um n�mero: ");
        scanf("%d", &numero);
    } while (numero != 0); // Continua solicitando at� que um n�mero positivo seja inserido

    printf("O n�mero inserido �: %d\n", numero);

    return 0;
}
