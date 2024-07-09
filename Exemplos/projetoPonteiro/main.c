#include <stdio.h>
#include <stdlib.h>
/*
**CONCEITO**
Um ponteiro � uma vari�vel que cont�m como valor o *ENDERE�O DE MEM�RIA* de outra vari�vel.
Em C, os ponteiros s�o utilizados para manipula��o direta de mem�ria e para passagem eficiente de grandes blocos de dados para FUN��ES.

**DECLARA��O DO PONTEIRO**:
Um ponteiro � declarado usando o operador *, que indica que a vari�vel � um ponteiro para o tipo especificado.

DECLARA��O
int *ptr;  // Ponteiro para um inteiro

Obten��o do Endere�o:
    int x = 10;
    int *ptr = &x;  // ptr cont�m o endere�o de x

Acesso ao Valor Apontado:
    int y = *ptr;  // y recebe o valor de x (10)

Manipula��o B�sica de Ponteiros:

    int x = 10;
    int *ptr = &x;

    // Alterando o valor de x atrav�s do ponteiro ptr
    *ptr = 20;

    // Imprimindo o novo valor de x
    printf("Novo valor de x: %d\n", x);


Ponteiros e Arrays:

    int numeros[5] = {10, 20, 30, 40, 50};
    int *ptr = numeros;  // ptr aponta para o primeiro elemento do array

    // Imprimindo os elementos usando aritm�tica de ponteiros
    printf("Elementos do array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // *(ptr + i) acessa o elemento i do array
    }
    printf("\n");


Fun��o com Ponteiro como Par�metro:

void dobrarValor(int *ptr) {
    *ptr = (*ptr) * 2;
}

int main(){

    int x = 10;

    // Chamando a fun��o e passando o endere�o de x
    dobrarValor(&x);

    // Imprimindo o novo valor de x ap�s a fun��o
    printf("Novo valor de x: %d\n", x);
    return 0;
}
*/



int main()
{




    printf("Hello world!\n");
    return 0;
}
