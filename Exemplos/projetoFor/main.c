#include <stdio.h>

int main() {
    int numero;
int vezes;
    // Solicita ao usu�rio para digitar um n�mero
    printf("Digite um n�mero para exibir a sua tabuada: ");
    scanf("%d", &numero); // L� o n�mero digitado pelo usu�rio

    // Exibe a tabuada do n�mero fornecido
    printf("Tabuada do %d:\n", numero);
    for (int i = 1; i <= 10; i++) {

        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}


// for( variavel que ser� contada; Contagem; incremento )







