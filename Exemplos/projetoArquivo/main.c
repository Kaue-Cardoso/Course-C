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
    "r" (read) Abre o arquivo para LEITURA. O ponteiro do arquivo é posicionado no início do arquivo. Se o arquivo não existir, a abertura falha.
    "w" (write) Abre o arquivo para escrita. Se o arquivo já existir, seu conteúdo é apagado. Se o arquivo não existir, ele é criado. O ponteiro do arquivo é posicionado no início do arquivo.
    "a" (append) Abre o arquivo para escrita, mas mantém o conteúdo existente intacto. O ponteiro do arquivo é posicionado no final do arquivo. Se o arquivo não existir, ele é criado.
    */

    //fprintf = Escreve dados em um arquivo formatado.
    fprintf(arquivo, "Este é um exemplo de texto: %d\n", numero);

    //fputs: Escreve uma string em um arquivo.
    fputs("Exemplo de texto", arquivo);

    //fscanf: Lê dados de um arquivo formatado.
    fscanf(arquivo, "%s %d", string, &numero);

    //fgets: Lê uma linha de texto de um arquivo.
    char linha[100];
    fgets(linha, 100, arquivo);

    //Fecha um arquivo aberto.
    fclose(arquivo); // Fecha o arquivo que foi aberto anteriormente


    return 0;
}
