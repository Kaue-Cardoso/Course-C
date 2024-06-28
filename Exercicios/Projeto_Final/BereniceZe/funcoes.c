#include "funcoes.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fun��o auxiliar para gerar um ID �nico
int gerarIdUnicoCliente()
{
    int id = 0;
    int clienteId;
    FILE *file = fopen("cadastroClientes.txt", "r");

    if (file)
    {
        char linha[256];
        while (fgets(linha, sizeof(linha), file))
        {
            if (sscanf(linha, "ID: %d", &clienteId) == 1)
            {
                if (clienteId > id)
                {
                    id = clienteId;
                }
            }
        }
        fclose(file);
    }
    return id + 1;
}
int gerarIdUnicoProduto()
{
    int id = 0;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");

    if (file)
    {
        while (fscanf(file, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
        {
            if (produto.id > id)
            {
                id = produto.id;
            }
        }
        fclose(file);
    }
    return id + 1;
}
int gerarIdUnicoCategoria()
{
    int id = 0;
    Categoria categoria;
    FILE *file = fopen("categorias.txt", "r");

    if (file)
    {
        while (fscanf(file, "%d %s", &categoria.id, categoria.nome) != EOF)
        {
            if (categoria.id > id)
            {
                id = categoria.id;
            }
        }
        fclose(file);
    }
    return id + 1;
}
int gerarIdUnicoCompra()
{
    int id = 0;
    Compra compra;
    FILE *file = fopen("compras.txt", "r");

    if (file)
    {
        while (fscanf(file, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
        {
            if (compra.id > id)
            {
                id = compra.id;
            }
        }
        fclose(file);
    }
    return id + 1;
}

// ###############################################################
// -----------------Inicio Menu Principal-------------------------
// ###############################################################
void menuPrincipal()
{
    printf("Menu Principal\n");
    printf("1. Cadastros\n");
    printf("2. Vendas\n");
    printf("3. Relatorios\n");
    printf("4. Sair\n");
}

// ###############################################################
// -----------------Inicio Cadastros -------------------------
// ###############################################################
void cadastros()
{
    int opcao=0;
    system("cls");
    printf("Voce escolheu Cadastros.\n");
    do
    {
        printf("Menu Cadastros\n");
        printf("1. Cadastrar Usu�rio\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Cadastrar Produto\n");
        printf("4. Retornar ao Menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            cadastroUsuarios();
            break;
        case 2:
            cadastroClientes();
            //cadastroClientes();
            break;
        case 3:
            cadastroProdutos();
            //cadastroProdutos();
            break;
        case 4:
            printf("Retornando...\n");
            return 1;
        default:
            printf("Opcao Errada. Tente Novamente");
        }
    }
    while (opcao < 1 || opcao > 5);
    return 0;
}
void relatorios()
{
    int opcao = 0;
    do
    {
        system("cls");
        printf("Menu Relatorios\n1 - Usu�rios\n2 - Clientes\n 3 - Produtos\n4 - Vendas\n5 - Sair\n");
        printf("Selecione a op��o Desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            listarUsuarios();
            break;
        case 2:
            listarClientes();
            break;
        case 3:
            listarProdutos();
            break;
        case 4:
            listarVendasFinalizadas();
            break;
        case 5:
            printf("Sair....\n");
            break;
        }
    }
    while (opcao != 5);
}

// ###############################################################
// -----------------Inicio Cadastro Usuario-------------------------
// ###############################################################
void cadastroUsuarios()
{
    int opcao=0;
    do
    {
        printf("Menu de Cadastro de Usu�rios\n");
        printf("1 - Cadastrar Usuario\n");
        printf("2 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            printf("Retornando ao Principal...\n");
            return 0;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }

    }
    while (opcao != 2);
}
void cadastrarUsuario()
{
    char login[13];
    char senha[9];
    int tipo;
    FILE *file = fopen("cadastroUsuarios.txt", "a");

    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Cadastro de Usu�rio\n");

    // Valida��o do login
    do
    {
        printf("Digite o login (8-12 caracteres): ");
        scanf("%s", login);
    }
    while (strlen(login) < 8 || strlen(login) > 12);  // Valida��o do login: repete at� que o login tenha entre 8 e 12 caracteres

    // Valida��o da senha
    do
    {
        printf("Digite a senha (6-8 caracteres): ");
        scanf("%s", senha);
    }
    while (strlen(senha) < 6 || strlen(senha) > 8);  // Valida��o de senha: repete at� que tenha entre 6 a 8 caracteres

    // Escolha do tipo
    do
    {
        printf("Escolha o tipo de usu�rio:\n1. Administrador do sistema\n2. Usu�rio\n");
        printf("Digite o n�mero correspondente ao tipo: ");
        scanf("%d", &tipo);
    }
    while (tipo != 1 && tipo != 2);

    // Armazenar no arquivo
    fprintf(file, "Login: %s\nSenha: %s\nTipo: %d\n\n", login, senha, tipo);

    fclose(file);
    printf("Usu�rio cadastrado com sucesso!\n");
    getchar(); // Espera pelo Enter
}
void listarUsuarios()
{
    char linha[256];
    FILE *file = fopen("cadastroUsuarios.txt", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Lista de Usu�rios Cadastrados:\n");
    while (fgets(linha, sizeof(linha), file))
    {
        printf("%s", linha);
    }

    fclose(file);
    printf("\nPressione Enter para continuar...");
    getchar(); // Espera pelo Enter
    getchar(); // Captura o Enter adicional

}


// ###############################################################
// -----------------Valida��o de ADM-------------------------
// ###############################################################
int validarAdministrador(const char *login, const char *senha)
{
    char linha[256]; // Buffer para armazenar cada linha lida do arquivo
    FILE *file = fopen("cadastroUsuarios.txt", "r"); // Abre o arquivo para leitura

    if (!file)   // Verifica se houve erro na abertura do arquivo
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0; // Retorna 0 para indicar falha na valida��o
    }

    Usuario user; // Vari�vel para armazenar temporariamente os dados de cada usu�rio lido do arquivo

    while (fgets(linha, sizeof(linha), file))   // Loop para ler cada linha do arquivo
    {
        if (strstr(linha, "Login: ") == linha)   // Verifica se a linha come�a com "Login: "
        {
            sscanf(linha + strlen("Login: "), "%s", user.login); // Extrai o login da linha

            fgets(linha, sizeof(linha), file); // L� a pr�xima linha para obter a senha
            if (strstr(linha, "Senha: ") == linha)   // Verifica se a linha come�a com "Senha: "
            {
                sscanf(linha + strlen("Senha: "), "%s", user.senha); // Extrai a senha da linha

                fgets(linha, sizeof(linha), file); // L� a pr�xima linha para obter o tipo
                if (strstr(linha, "Tipo: ") == linha)   // Verifica se a linha come�a com "Tipo: "
                {
                    sscanf(linha + strlen("Tipo: "), "%d", &user.tipo); // Extrai o tipo da linha

                    if (strcmp(user.login, login) == 0 && strcmp(user.senha, senha) == 0 && user.tipo == 1)
                    {
                        fclose(file); // Fecha o arquivo ap�s encontrar o administrador v�lido
                        return 1; // Retorna 1 para indicar sucesso na valida��o do administrador
                    }
                }
            }
        }
    }

    fclose(file); // Fecha o arquivo ap�s terminar de ler todas as linhas

    return 0; // Retorna 0 se n�o encontrou um administrador v�lido com o login e senha fornecidos
}

// ###############################################################
// -----------------Inicio Cadastro Cliente-------------------------
// ###############################################################
void cadastrarCliente()
{
    Cliente cliente;
    FILE *file = fopen("cadastroClientes.txt", "a");

    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Cadastro de Cliente\n");

    // Gera um ID �nico para o novo cliente
    cliente.id = gerarIdUnicoCliente();

    // Solicita��o dos dados do cliente
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", cliente.nomeCompleto);  // L� at� encontrar uma nova linha
    printf("Digite o nome social: ");
    scanf(" %[^\n]", cliente.nomeSocial);  // L� at� encontrar uma nova linha
    printf("Digite o CPF (apenas n�meros, 11 d�gitos): ");
    scanf("%s", cliente.cpf);
    printf("Digite o endere�o - Rua: ");
    scanf(" %[^\n]", cliente.enderecoRua);
    printf("Digite o endere�o - N�mero: ");
    scanf("%d", &cliente.enderecoNumero);
    printf("Digite o endere�o - Bairro: ");
    scanf(" %[^\n]", cliente.enderecoBairro);
    printf("Digite o celular (formato: DDDXXXXX-XXXX): ");
    scanf("%s", cliente.celular);

    // Armazenar no arquivo
    fprintf(file, "ID: %d\nNome Completo: %s\nNome Social: %s\nCPF: %s\nEndere�o Rua: %s\nEndere�o N�mero: %d\nEndere�o Bairro: %s\nCelular: %s\n\n",
            cliente.id, cliente.nomeCompleto, cliente.nomeSocial, cliente.cpf, cliente.enderecoRua, cliente.enderecoNumero, cliente.enderecoBairro, cliente.celular);

    fclose(file);
    printf("Cliente cadastrado com sucesso!\n");
    getchar(); // Espera pelo Enter
}

void listarClientes()
{
    char linha[256];
    FILE *file = fopen("cadastroClientes.txt", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Lista de Clientes Cadastrados:\n");
    while (fgets(linha, sizeof(linha), file))
    {
        printf("%s", linha);
    }

    fclose(file);
    printf("\nPressione Enter para continuar...");
    getchar(); // Espera pelo Enter
    getchar(); // Captura o Enter adicional
}
//Menu Cadastro Clientes
void cadastroClientes()
{
    int opcao = 0;
    do
    {
        printf("Menu de Cadastro de Clientes\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarCliente();
            break;
        case 2:
            printf("Retornando ao Principal...\n");
            return 0;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 2);
    return 0;
}

// ###############################################################
// -----------------Inicio Cadastro Produtos-------------------------
// ###############################################################

//Fun��o para calcular Margem de Lucro
void calcularMargemLucro(Produto *produto)
{
    produto->margemLucro = ((produto->precoVenda - produto->precoCompra) / produto->precoCompra) * 100;
}

// ###############################################################
// ----------------- Cadastro Categorias -------------------------
// ###############################################################
int categoriaExiste(const char *nomeCategoria)
{
    Categoria categoria;
    FILE *file = fopen("categorias.txt", "r");

    if (!file)
    {
        return 0;
    }

    while (fscanf(file, "%d %s", &categoria.id, categoria.nome) != EOF)
    {
        if (strcmp(categoria.nome, nomeCategoria) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void cadastrarCategoria()
{
    Categoria categoria;
    FILE *file = fopen("categorias.txt", "a");

    if (!file)
    {
        printf("Erro ao abrir o arquivo de categorias!\n");
        return;
    }

    printf("Digite o nome da categoria: ");
    scanf("%s", categoria.nome);

    if (categoriaExiste(categoria.nome))
    {
        printf("Categoria j� existe!\n");
        fclose(file);
        return;
    }

    categoria.id = gerarIdUnicoCategoria();
    fprintf(file, "%d %s\n", categoria.id, categoria.nome);
    fclose(file);
    printf("Categoria cadastrada com sucesso!\n");
}

void listarCategorias()
{
    Categoria categoria;
    FILE *file = fopen("categorias.txt", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo de categorias!\n");
        return;
    }

    printf("Lista de Categorias:\n");
    while (fscanf(file, "%d %s", &categoria.id, categoria.nome) != EOF)
    {
        printf("ID: %d\nNome: %s\n\n", categoria.id, categoria.nome);
    }

    fclose(file);
}

void cadastroCategorias()
{
    int opcao = 0;
    do
    {
        printf("Menu de Cadastro de Categorias\n");
        printf("1 - Cadastrar Categoria\n");
        printf("2 - Listar Categorias\n");
        printf("3 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarCategoria();
            break;
        case 2:
            listarCategorias();
            break;
        case 3:
            printf("Retornando ao menu Principal...\n");
            return;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 3);
}

// ###############################################################
// ----------------- Cadastro De Produtos-------------------------
// ###############################################################
void cadastrarProduto()
{
    Produto produto;
    FILE *file = fopen("produtos.txt", "a");
    FILE *catFile = fopen("categorias.txt", "r");
    Categoria categoria;
    int categoriaId;

    if (!file || !catFile)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    produto.id = gerarIdUnicoProduto();
    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);
    printf("Digite o pre�o de compra: ");
    scanf("%f", &produto.precoCompra);
    printf("Digite o pre�o de venda: ");
    scanf("%f", &produto.precoVenda);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidadeEstoque);

    produto.estoqueMinimo = 3;  // Estoque m�nimo fixo
    calcularMargemLucro(&produto);

    listarCategorias();
    printf("Digite o ID da categoria do produto: ");
    scanf("%d", &categoriaId);

    while (fscanf(catFile, "%d %s", &categoria.id, categoria.nome) != EOF)
    {
        if (categoria.id == categoriaId)
        {
            strcpy(produto.categoria, categoria.nome);
            break;
        }
    }

    fprintf(file, "%d %s %.2f %.2f %.2f %d %d %s\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
    fclose(file);
    fclose(catFile);
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos()
{
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Lista de Produtos:\n");
    while (fscanf(file, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
    {
        printf("ID: %d\nNome: %s\nPre�o de Compra: %.2f\nPre�o de Venda: %.2f\nMargem de Lucro: %.2f%%\nQuantidade em Estoque: %d\nEstoque M�nimo: %d\nCategoria: %s\n\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
    }

    fclose(file);
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();
}

void alterarPrecoVenda()
{
    int id, encontrado = 0;
    float novoPrecoVenda;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    listarProdutos();
    printf("Digite o ID do produto para alterar o pre�o de venda: ");
    scanf("%d", &id);
    printf("Digite o novo pre�o de venda: ");
    scanf("%f", &novoPrecoVenda);

    while (fscanf(file, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
    {
        if (produto.id == id)
        {
            produto.precoVenda = novoPrecoVenda;
            calcularMargemLucro(&produto);
            encontrado = 1;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d %s\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado)
    {
        printf("Pre�o de venda atualizado com sucesso!\n");
    }
    else
    {
        printf("Produto n�o encontrado!\n");
    }
}

void adicionarEstoque()
{
    int id, quantidade, encontrado = 0;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    listarProdutos();
    printf("Digite o ID do produto para adicionar estoque: ");
    scanf("%d", &id);
    printf("Digite a quantidade a adicionar: ");
    scanf("%d", &quantidade);

    while (fscanf(file, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
    {
        if (produto.id == id)
        {
            produto.quantidadeEstoque += quantidade;
            encontrado = 1;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d %s\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado)
    {
        printf("Estoque atualizado com sucesso!\n");
    }
    else
    {
        printf("Produto n�o encontrado!\n");
    }
}

void apagarProduto()
{
    int id, encontrado = 0;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    listarProdutos();
    printf("Digite o ID do produto a ser removido: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
    {
        if (produto.id == id)
        {
            encontrado = 1;
            printf("Produto %s removido.\n", produto.nome);
            continue;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d %s\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (!encontrado)
    {
        printf("Produto n�o encontrado!\n");
    }
}

void cadastroProdutos()
{
    int opcao = 0;
    do
    {
        system("cls");
        printf("Menu de Cadastro de Produtos\n");
        printf("1 - Categorias\n");
        printf("2 - Cadastrar Produto\n");
        printf("3 - Alterar Pre�o de Venda\n");
        printf("4 - Adicionar Estoque\n");
        printf("5 - Apagar Produto\n");
        printf("6 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastroCategorias();
            break;
        case 2:
            cadastrarProduto();
            break;
        case 3:
            alterarPrecoVenda();
            break;
        case 4:
            adicionarEstoque();
            break;
        case 5:
            apagarProduto();
            break;
        case 6:
            printf("Retornando ao menu Principal...\n");
            return;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 6);
}

// ###############################################################
// -----------------Inicio Vendas -------------------------
// ###############################################################
void cadastrarNovaVenda()
{
    Compra compra;
    ItemCompra item;
    Produto produto;
    Cliente cliente;
    int idProduto, quantidade;
    FILE *comprasFile = fopen("compras.txt", "a");
    FILE *itensFile = fopen("itensCompras.txt", "a");

    if (!comprasFile || !itensFile)
    {
        printf("Erro ao abrir os arquivos de compras!\n");
        return;
    }

    compra.id = gerarIdUnicoCompra();
    compra.finalizada = 0;
    compra.total = 0.0;

    // Lista os clientes e solicita o ID do cliente
    listarClientes();
    printf("Digite o ID do cliente: ");
    scanf("%d", &compra.idCliente);

    // Verifica se o cliente existe e pega o nome dele
    FILE *clientesFile = fopen("cadastroClientes.txt", "r");
    int clienteEncontrado = 0;
    char linha[256];

    if (clientesFile)
    {
        while (fgets(linha, sizeof(linha), clientesFile))
        {
            if (sscanf(linha, "ID: %d", &cliente.id) == 1 && cliente.id == compra.idCliente)
            {
                clienteEncontrado = 1;
                fgets(linha, sizeof(linha), clientesFile);  // Nome Completo
                sscanf(linha, "Nome Completo: %[^\n]", cliente.nomeCompleto);
                break;
            }
        }
        fclose(clientesFile);
    }

    if (!clienteEncontrado)
    {
        printf("Cliente n�o encontrado!\n");
        fclose(comprasFile);
        fclose(itensFile);
        return;
    }

    while (1)
    {
        listarProdutos();
        printf("Digite o ID do produto (ou -1 para finalizar): ");
        scanf("%d", &idProduto);
        if (idProduto == -1)
        {
            break;
        }

        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);

        FILE *produtosFile = fopen("produtos.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");

        if (!produtosFile || !tempFile)
        {
            printf("Erro ao abrir o arquivo de produtos!\n");
            fclose(comprasFile);
            fclose(itensFile);
            return;
        }

        while (fscanf(produtosFile, "%d %s %f %f %f %d %d %s", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo, produto.categoria) != EOF)
        {
            if (produto.id == idProduto)
            {
                if (produto.quantidadeEstoque >= quantidade)
                {
                    produto.quantidadeEstoque -= quantidade;

                    item.idCompra = compra.id;
                    item.idProduto = idProduto;
                    item.quantidade = quantidade;
                    item.precoUnitario = produto.precoVenda;

                    fprintf(itensFile, "%d %d %d %.2f\n", item.idCompra, item.idProduto, item.quantidade, item.precoUnitario);
                    compra.total += item.precoUnitario * item.quantidade;
                }
                else
                {
                    printf("Quantidade em estoque insuficiente!\n");
                }
            }
            fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d %s\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo, produto.categoria);
        }

        fclose(produtosFile);
        fclose(tempFile);
        remove("produtos.txt");
        rename("temp.txt", "produtos.txt");
    }

    // Adiciona a nova compra no arquivo com o total atualizado
    fprintf(comprasFile, "%d %d %.2f %d\n", compra.id, compra.idCliente, compra.total, compra.finalizada);

    fclose(comprasFile);
    fclose(itensFile);
    printf("Venda cadastrada com sucesso para o cliente: %s\n", cliente.nomeCompleto);
}
void comprasEmAberto()
{
    Compra compra;
    ItemCompra item;
    Cliente cliente;
    FILE *comprasFile = fopen("compras.txt", "r");
    FILE *itensFile = fopen("itensCompras.txt", "r");
    FILE *clientesFile = fopen("cadastroClientes.txt", "r");

    if (!comprasFile || !itensFile || !clientesFile)
    {
        printf("Erro ao abrir o arquivo de compras, itens de compras ou clientes!\n");
        return;
    }

    printf("Compras em Aberto:\n");
    while (fscanf(comprasFile, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.finalizada == 0)
        {
            char linha[256];
            int clienteEncontrado = 0;
            fseek(clientesFile, 0, SEEK_SET);
            while (fgets(linha, sizeof(linha), clientesFile))
            {
                if (sscanf(linha, "ID: %d", &cliente.id) == 1 && cliente.id == compra.idCliente)
                {
                    clienteEncontrado = 1;
                    fgets(linha, sizeof(linha), clientesFile);
                    sscanf(linha, "Nome Completo: %[^\n]", cliente.nomeCompleto);
                    break;
                }
            }

            if (clienteEncontrado)
            {
                printf("ID: %d | Cliente: %s | Total: %.2f\n", compra.id, cliente.nomeCompleto, compra.total);
            }
            else
            {
                printf("ID: %d | Cliente ID: %d | Total: %.2f\n", compra.id, compra.idCliente, compra.total);
            }

            printf("Itens Comprados:\n");
            fseek(itensFile, 0, SEEK_SET);
            while (fscanf(itensFile, "%d %d %d %f", &item.idCompra, &item.idProduto, &item.quantidade, &item.precoUnitario) != EOF)
            {
                if (item.idCompra == compra.id)
                {
                    printf("  Produto ID: %d | Quantidade: %d | Pre�o Unit�rio: %.2f\n", item.idProduto, item.quantidade, item.precoUnitario);
                }
            }
        }
    }

    fclose(comprasFile);
    fclose(itensFile);
    fclose(clientesFile);
}

void finalizarCompra()
{
    int idCompra, encontrado = 0, pagamentoOk = 0;
    Compra compra;
    FILE *file = fopen("compras.txt", "r+");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile)
    {
        printf("Erro ao abrir o arquivo de compras!\n");
        return;
    }

    printf("Digite o ID da compra a ser finalizada: ");
    scanf("%d", &idCompra);

    while (fscanf(file, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.id == idCompra && compra.finalizada == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        fclose(file);
        fclose(tempFile);
        printf("Compra n�o encontrada ou j� finalizada!\n");
        return;
    }

    while (!pagamentoOk)
    {
        int opcaoPagamento;
        printf("Menu:\n");
        printf("1. Pagamento no cart�o\n");
        printf("2. Pagamento em dinheiro\n");
        printf("3. Retornar ao Menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcaoPagamento);

        switch (opcaoPagamento)
        {
        case 1:
        {
            int parcelas;
            printf("Digite o n�mero de parcelas (1 a 6): ");
            scanf("%d", &parcelas);
            if (parcelas < 1 || parcelas > 6)
            {
                printf("N�mero de parcelas inv�lido!\n");
                break;
            }
            float valorParcela = compra.total / parcelas;
            printf("Valor de cada parcela: %.2f\n", valorParcela);
            printf("1. Pagamento Ok\n");
            printf("0. Pagamento no cart�o N�O Confirmado\n");
            int confirmacao;
            scanf("%d", &confirmacao);
            if (confirmacao == 1)
            {
                pagamentoOk = 1;
            }
            else
            {
                printf("Pagamento n�o confirmado, escolha novamente a forma de pagamento.\n");
            }
            break;
        }
        case 2:
        {
            float valorRecebido;
            printf("Digite o valor recebido: ");
            scanf("%f", &valorRecebido);
            if (valorRecebido < compra.total)
            {
                printf("Valor recebido insuficiente!\n");
                break;
            }
            float troco = valorRecebido - compra.total;
            printf("Troco: %.2f\n", troco);
            pagamentoOk = 1;
            break;
        }
        case 3:
        {
            fclose(file);
            fclose(tempFile);
            return;
        }
        default:
        {
            printf("Op��o inv�lida!\n");
            break;
        }
        }
    }

    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.id == idCompra && compra.finalizada == 0)
        {
            compra.finalizada = 1;
        }
        fprintf(tempFile, "%d %d %.2f %d\n", compra.id, compra.idCliente, compra.total, compra.finalizada);
    }

    fclose(file);
    fclose(tempFile);
    remove("compras.txt");
    rename("temp.txt", "compras.txt");

    printf("Compra finalizada com sucesso!\n");
}

void cancelarCompra()
{
    int idCompra, encontrado = 0;
    char login[50], senha[50];
    Compra compra;
    FILE *file = fopen("compras.txt", "r+");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile)
    {
        printf("Erro ao abrir o arquivo de compras!\n");
        return;
    }

    printf("Digite o ID da compra a ser cancelada: ");
    scanf("%d", &idCompra);

    while (fscanf(file, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.id == idCompra && compra.finalizada == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        fclose(file);
        fclose(tempFile);
        printf("Compra n�o encontrada ou j� finalizada!\n");
        return;
    }

    printf("Digite o login do administrador: ");
    scanf("%s", login);
    printf("Digite a senha do administrador: ");
    scanf("%s", senha);

    if (!validarAdministrador(login, senha))
    {
        printf("Login ou senha inv�lidos! Cancelamento n�o autorizado.\n");
        fclose(file);
        fclose(tempFile);
        return;
    }

    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.id == idCompra && compra.finalizada == 0)
        {
            continue;
        }
        fprintf(tempFile, "%d %d %.2f %d\n", compra.id, compra.idCliente, compra.total, compra.finalizada);
    }

    fclose(file);
    fclose(tempFile);
    remove("compras.txt");
    rename("temp.txt", "compras.txt");

    printf("Compra cancelada com sucesso!\n");
}

void listarVendasFinalizadas()
{
    Compra compra;
    ItemCompra item;
    Cliente cliente;
    FILE *comprasFile = fopen("compras.txt", "r");
    FILE *itensFile = fopen("itensCompras.txt", "r");
    FILE *clientesFile = fopen("cadastroClientes.txt", "r");

    if (!comprasFile || !itensFile || !clientesFile)
    {
        printf("Erro ao abrir os arquivos de compras, itens de compras ou clientes!\n");
        return;
    }

    printf("Vendas Finalizadas:\n");
    while (fscanf(comprasFile, "%d %d %f %d", &compra.id, &compra.idCliente, &compra.total, &compra.finalizada) != EOF)
    {
        if (compra.finalizada == 1)
        {
            char linha[256];
            int clienteEncontrado = 0;
            fseek(clientesFile, 0, SEEK_SET);
            while (fgets(linha, sizeof(linha), clientesFile))
            {
                if (sscanf(linha, "ID: %d", &cliente.id) == 1 && cliente.id == compra.idCliente)
                {
                    clienteEncontrado = 1;
                    fgets(linha, sizeof(linha), clientesFile);
                    sscanf(linha, "Nome Completo: %[^\n]", cliente.nomeCompleto);
                    break;
                }
            }

            if (clienteEncontrado)
            {
                printf("ID: %d | Cliente: %s | Total: %.2f\n", compra.id, cliente.nomeCompleto, compra.total);
            }
            else
            {
                printf("ID: %d | Cliente ID: %d | Total: %.2f\n", compra.id, compra.idCliente, compra.total);
            }

            printf("Itens Comprados:\n");
            fseek(itensFile, 0, SEEK_SET);
            while (fscanf(itensFile, "%d %d %d %f", &item.idCompra, &item.idProduto, &item.quantidade, &item.precoUnitario) != EOF)
            {
                if (item.idCompra == compra.id)
                {
                    printf("  Produto ID: %d | Quantidade: %d | Pre�o Unit�rio: %.2f\n", item.idProduto, item.quantidade, item.precoUnitario);
                }
            }
        }
    }

    fclose(comprasFile);
    fclose(itensFile);
    fclose(clientesFile);
    printf("\nPressione Enter para continuar...");
    getchar(); // Espera pelo Enter
    getchar(); // Captura o Enter adicional

}

void vendas()
{
    int opcao;
    do
    {
        printf("Menu Vendas\n");
        printf("1. Cadastrar Nova Venda\n");
        printf("2. Compras Em Aberto\n");
        printf("3. Cancelar Compras\n");
        printf("4. Finalizar Compra\n");
        printf("5. Retornar ao Menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            cadastrarNovaVenda();
            break;
        case 2:
            comprasEmAberto();
            break;
        case 3:
            cancelarCompra();
            break;
        case 4:
            finalizarCompra();
            break;
        case 5:
            return;
        default:
            printf("Opcao Errada. Tente Novamente\n");
        }
    }
    while (opcao != 5);
}
