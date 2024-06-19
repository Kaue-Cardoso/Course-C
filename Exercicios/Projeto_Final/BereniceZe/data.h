#ifndef DATA_H
#define DATA_H

typedef struct {
    char login[13];
    char senha[9];
    int tipo;
} Usuario;

typedef struct {
    char nomeCompleto[100];
    char nomeSocial[100];
    char cpf[12];
    char enderecoRua[100];
    int enderecoNumero;
    char enderecoBairro[100];
    char celular[15];
} Cliente;

typedef struct {
    int id;
    char nome[50];
} Categoria;

typedef struct {
    int id;
    char nome[50];
    float precoCompra;
    float precoVenda;
    float margemLucro;
    int quantidadeEstoque;
    int estoqueMinimo;
} Produto;

#endif // DATA_H
