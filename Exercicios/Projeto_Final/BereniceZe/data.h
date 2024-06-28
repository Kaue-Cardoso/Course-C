#ifndef DATA_H
#define DATA_H

typedef struct {
    char login[13];
    char senha[9];
    int tipo;
} Usuario;

typedef struct {
    int id;
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
    char categoria[50];
} Produto;



typedef struct {
    int id;
    int idCliente;
    float total;
    int finalizada; // 0 para não finalizada, 1 para finalizada
} Compra;

typedef struct {
    int idCompra;
    int idProduto;
    int quantidade;
    float precoUnitario;
} ItemCompra;


#endif // DATA_H
