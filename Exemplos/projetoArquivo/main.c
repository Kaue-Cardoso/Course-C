#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Como Utilizar Arquivos\n");

    FILE *arquivo;

    //fopen =  Abre um arquivo para leitura ou escrita.
    arquivo = fopen("arquivo.txt", "r"); // Abre o arquivo.txt para leitura
    /*
    MODOS DE ABERTURA DO ARQUIVO:
    "r" (read) Abre o arquivo para LEITURA. O ponteiro do arquivo � posicionado no in�cio do arquivo. Se o arquivo n�o existir, a abertura falha.
    "w" (write) Abre o arquivo para escrita. Se o arquivo j� existir, seu conte�do � apagado. Se o arquivo n�o existir, ele � criado. O ponteiro do arquivo � posicionado no in�cio do arquivo.
    "a" (append) Abre o arquivo para escrita, mas mant�m o conte�do existente intacto. O ponteiro do arquivo � posicionado no final do arquivo. Se o arquivo n�o existir, ele � criado.
    */

    //fprintf = Escreve dados em um arquivo formatado.
    fprintf(arquivo, "Este � um exemplo de texto: %d\n", numero);

    //fputs: Escreve uma string em um arquivo.
    fputs("Exemplo de texto", arquivo);

    //fscanf: L� dados de um arquivo formatado.
    fscanf(arquivo, "%s %d", string, &numero);

    //fgets: L� uma linha de texto de um arquivo.
    char linha[100];
    fgets(linha, 100, arquivo);

    //Fecha um arquivo aberto.
    fclose(arquivo); // Fecha o arquivo que foi aberto anteriormente


    return 0;
}
