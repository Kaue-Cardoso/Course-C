#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Declara��o: Um array em C � declarado especificando o tipo de seus elementos e o n�mero de elementos que ele conter�. Por exemplo:
    int numeros[10];

    Inicializa��o expl�cita:
    int numeros[5] = {1, 2, 3, 4, 5};
    Inicializa��o impl�cita:
    int numeros[] = {1, 2, 3, 4, 5};
    */
    int numeros[] = {1, 2, 3, 4, 5}, valor;
    printf("Seja Bem Vindo ao Sistema\nNumeros Dentro do Array ");
    for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]);
    }
    valor = numeros[2];  // Acessa o terceiro elemento do array
    printf("\nValor do terceiro campo do vetor atual: %d", valor);
    printf("\nDigite um novo valor para o terceiro campo: ");
    scanf("%d", &valor );
    numeros[2] = valor;  // Acessa o terceiro elemento do array
    for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]);
    }

    return 0;
}
