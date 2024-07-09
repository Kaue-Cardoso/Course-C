#include <stdio.h>
#include <stdlib.h>
/*
**CONCEITO**
Um ponteiro é uma variável que contém como valor o *ENDEREÇO DE MEMÓRIA* de outra variável.
Em C, os ponteiros são utilizados para manipulação direta de memória e para passagem eficiente de grandes blocos de dados para FUNÇÕES.

**DECLARAÇÃO DO PONTEIRO**:
Um ponteiro é declarado usando o operador *, que indica que a variável é um ponteiro para o tipo especificado.

DECLARAÇÃO
int *ptr;  // Ponteiro para um inteiro

Obtenção do Endereço:
    int x = 10;
    int *ptr = &x;  // ptr contém o endereço de x

Acesso ao Valor Apontado:
    int y = *ptr;  // y recebe o valor de x (10)

Manipulação Básica de Ponteiros:

    int x = 10;
    int *ptr = &x;

    // Alterando o valor de x através do ponteiro ptr
    *ptr = 20;

    // Imprimindo o novo valor de x
    printf("Novo valor de x: %d\n", x);


Ponteiros e Arrays:

    int numeros[5] = {10, 20, 30, 40, 50};
    int *ptr = numeros;  // ptr aponta para o primeiro elemento do array

    // Imprimindo os elementos usando aritmética de ponteiros
    printf("Elementos do array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // *(ptr + i) acessa o elemento i do array
    }
    printf("\n");


Função com Ponteiro como Parâmetro:

void dobrarValor(int *ptr) {
    *ptr = (*ptr) * 2;
}

int main(){

    int x = 10;

    // Chamando a função e passando o endereço de x
    dobrarValor(&x);

    // Imprimindo o novo valor de x após a função
    printf("Novo valor de x: %d\n", x);
    return 0;
}
*/



int main()
{




    printf("Hello world!\n");
    return 0;
}
