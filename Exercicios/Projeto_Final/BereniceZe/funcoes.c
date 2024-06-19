#include "funcoes.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ###############################################################
// -----------------Inicio Menu Principal-------------------------
// ###############################################################

void menuPrincipal()
{
    printf("Menu Principal\n");
    printf("1. Cadastros\n");
    printf("2. Vendas\n");
    printf("3. Abertura de Caixa\n");
    printf("4. Fechamento de Caixa\n");
    printf("5. Relatorios\n");
    printf("6. Sair\n");
}

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
        printf("4. Cadastrar Categoria\n");
        printf("5. Retornar ao Menu Principal\n");
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
            printf("Fun��o Cadastrar ainda n�o implementada.\n");
            //cadastroCategorias();
            break;
        case 5:
            printf("Retornando...\n");
            return 1;
        default:
            printf("Opcao Errada. Tente Novamente");
        }
    }
    while (opcao < 1 || opcao > 5);
    return 0;
}
void vendas()
{
    printf("Voce escolheu Vendas.\n");
}
void aberturaDeCaixa()
{
    printf("Voce escolheu Abertura de Caixa.\n");
}
void fechamentoDeCaixa()
{
    printf("Voce escolheu Fechamento de Caixa.\n");
}
void relatorios()
{
    printf("Voce escolheu Relatorios.\n");
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
        printf("2 - Listar Usuarios\n");
        printf("3 - Remover Usuario\n");
        printf("4 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            listarUsuarios();
            break;
        case 3:
            printf("Ainda n�o implementado");
            //removerUsuario();
            break;
        case 4:
            printf("Retornando ao Principal...\n");
            return 0;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }

    }
    while (opcao != 4);
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
int validarAdministrador(const char *login, const char *senha) {
    char linha[256]; // Buffer para armazenar cada linha lida do arquivo
    FILE *file = fopen("cadastroUsuarios.txt", "r"); // Abre o arquivo para leitura

    if (!file) { // Verifica se houve erro na abertura do arquivo
        printf("Erro ao abrir o arquivo!\n");
        return 0; // Retorna 0 para indicar falha na valida��o
    }

    Usuario user; // Vari�vel para armazenar temporariamente os dados de cada usu�rio lido do arquivo

    while (fgets(linha, sizeof(linha), file)) { // Loop para ler cada linha do arquivo
        if (strstr(linha, "Login: ") == linha) { // Verifica se a linha come�a com "Login: "
            sscanf(linha + strlen("Login: "), "%s", user.login); // Extrai o login da linha

            fgets(linha, sizeof(linha), file); // L� a pr�xima linha para obter a senha
            if (strstr(linha, "Senha: ") == linha) { // Verifica se a linha come�a com "Senha: "
                sscanf(linha + strlen("Senha: "), "%s", user.senha); // Extrai a senha da linha

                fgets(linha, sizeof(linha), file); // L� a pr�xima linha para obter o tipo
                if (strstr(linha, "Tipo: ") == linha) { // Verifica se a linha come�a com "Tipo: "
                    sscanf(linha + strlen("Tipo: "), "%d", &user.tipo); // Extrai o tipo da linha

                    if (strcmp(user.login, login) == 0 && strcmp(user.senha, senha) == 0 && user.tipo == 1) {
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

/*
// FUN��O PARA REMOVER USUARIO
void removerUsuario() {
    char loginRemover[13];
    char senhaRemover[9];
    char loginAdmin[13];
    char senhaAdmin[9];
    int encontrou = 0;
    char linha[256];

    printf("Digite o login do usu�rio a ser removido: ");
    scanf("%s", loginRemover);
    printf("Digite a senha do usu�rio a ser removido: ");
    scanf("%s", senhaRemover);

    printf("Digite o login do administrador para validar a remo��o: ");
    scanf("%s", loginAdmin);
    printf("Digite a senha do administrador para validar a remo��o: ");
    scanf("%s", senhaAdmin);

    if (!validarAdministrador(loginAdmin, senhaAdmin)) {
        printf("Apenas administradores podem validar a remo��o de usu�rios.\n");
        return;
    }

    FILE *file = fopen("cadastroClientes.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Usuario user;
    while (fgets(linha, sizeof(linha), file)) {
        // Verifica se a linha come�a com "Login: "
        if (strstr(linha, "Login: ") == linha) {
            // Remove "Login: " da linha e extrai o login
            sscanf(linha + strlen("Login: "), "%s", user.login);

            // L� a pr�xima linha para extrair a senha
            fgets(linha, sizeof(linha), file);
            if (strstr(linha, "Senha: ") == linha) {
                // Remove "Senha: " da linha e extrai a senha
                sscanf(linha + strlen("Senha: "), "%s", user.senha);

                // L� a pr�xima linha para extrair o tipo
                fgets(linha, sizeof(linha), file);
                if (strstr(linha, "Tipo: ") == linha) {
                    // Remove "Tipo: " da linha e extrai o tipo
                    sscanf(linha + strlen("Tipo: "), "%d", &user.tipo);

                    // Comparar login e senha
                    if (strcmp(user.login, loginRemover) == 0 && strcmp(user.senha, senhaRemover) == 0) {
                        encontrou = 1;
                        printf("Usu�rio %s removido.\n", user.login);
                        continue; // Pular a escrita da linha no arquivo tempor�rio
                    }
                }
            }
        }
        fprintf(tempFile, "%s", linha); // Escrever a linha no arquivo tempor�rio
    }

    fclose(file);
    fclose(tempFile);

    remove("cadastroClientes.txt");
    rename("temp.txt", "cadastroClientes.txt");

    if (!encontrou) {
        printf("Usu�rio n�o encontrado ou senha incorreta.\n");
    }
}
*/
// ###############################################################
// -----------------Inicio Cadastro Cliente-------------------------
// ###############################################################
void cadastrarCliente() {
    Cliente cliente;
    FILE *file = fopen("cadastroClientes.txt", "a");

    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Cadastro de Cliente\n");

    // Solicita��o dos dados do cliente
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", cliente.nomeCompleto);  // L� at� encontrar uma nova linha
    printf("Digite o nome social (ou deixe em branco se n�o houver): ");
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
    fprintf(file, "Nome Completo: %s\nNome Social: %s\nCPF: %s\nEndere�o Rua: %s\nEndere�o N�mero: %d\nEndere�o Bairro: %s\nCelular: %s\n\n",
            cliente.nomeCompleto, cliente.nomeSocial, cliente.cpf, cliente.enderecoRua, cliente.enderecoNumero, cliente.enderecoBairro, cliente.celular);

    fclose(file);
    printf("Cliente cadastrado com sucesso!\n");
    getchar(); // Espera pelo Enter
}

void listarClientes() {
    char linha[256];
    FILE *file = fopen("cadastroClientes.txt", "r");

    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Lista de Clientes Cadastrados:\n");
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }

    fclose(file);
    printf("\nPressione Enter para continuar...");
    getchar(); // Espera pelo Enter
    getchar(); // Captura o Enter adicional
}

void cadastroClientes() {
    int opcao = 0;
    do {
        printf("Menu de Cadastro de Clientes\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Remover Cliente\n");
        printf("4 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                printf("Ainda n�o implementado");
                //removerCliente();
                break;
            case 4:
                printf("Retornando ao Principal...\n");
                return 0;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}

// ###############################################################
// -----------------Inicio Cadastro Produtos-------------------------
// ###############################################################
// Fun��o auxiliar para gerar um ID �nico
int gerarIdUnico() {
    static int ultimoId = 0;
    return ++ultimoId;
}
// Fun��o auxiliar para calcular a margem de lucro
void calcularMargemLucro(Produto *produto) {
    produto->margemLucro = ((produto->precoVenda - produto->precoCompra) / produto->precoCompra) * 100;
}
void cadastrarProduto() {
    Produto produto;
    FILE *file = fopen("produtos.txt", "a");

    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    produto.id = gerarIdUnico();
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

    fprintf(file, "%d %s %.2f %.2f %.2f %d %d\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo);
    fclose(file);
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");

    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Lista de Produtos:\n");
    while (fscanf(file, "%d %s %f %f %f %d %d", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo) != EOF) {
        printf("ID: %d\nNome: %s\nPre�o de Compra: %.2f\nPre�o de Venda: %.2f\nMargem de Lucro: %.2f%%\nQuantidade em Estoque: %d\nEstoque M�nimo: %d\n\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo);
    }

    fclose(file);
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();
}

void alterarPrecoVenda() {
    int id, encontrado = 0;
    float novoPrecoVenda;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o ID do produto para alterar o pre�o de venda: ");
    scanf("%d", &id);
    printf("Digite o novo pre�o de venda: ");
    scanf("%f", &novoPrecoVenda);

    while (fscanf(file, "%d %s %f %f %f %d %d", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo) != EOF) {
        if (produto.id == id) {
            produto.precoVenda = novoPrecoVenda;
            calcularMargemLucro(&produto);
            encontrado = 1;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado) {
        printf("Pre�o de venda atualizado com sucesso!\n");
    } else {
        printf("Produto n�o encontrado!\n");
    }
}

void adicionarEstoque() {
    int id, quantidade, encontrado = 0;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o ID do produto para adicionar estoque: ");
    scanf("%d", &id);
    printf("Digite a quantidade a adicionar: ");
    scanf("%d", &quantidade);

    while (fscanf(file, "%d %s %f %f %f %d %d", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo) != EOF) {
        if (produto.id == id) {
            produto.quantidadeEstoque += quantidade;
            encontrado = 1;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado) {
        printf("Estoque atualizado com sucesso!\n");
    } else {
        printf("Produto n�o encontrado!\n");
    }
}

void apagarProduto() {
    int id, encontrado = 0;
    Produto produto;
    FILE *file = fopen("produtos.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o ID do produto a ser removido: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %f %f %f %d %d", &produto.id, produto.nome, &produto.precoCompra, &produto.precoVenda, &produto.margemLucro, &produto.quantidadeEstoque, &produto.estoqueMinimo) != EOF) {
        if (produto.id == id) {
            encontrado = 1;
            printf("Produto %s removido.\n", produto.nome);
            continue;
        }
        fprintf(tempFile, "%d %s %.2f %.2f %.2f %d %d\n", produto.id, produto.nome, produto.precoCompra, produto.precoVenda, produto.margemLucro, produto.quantidadeEstoque, produto.estoqueMinimo);
    }

    fclose(file);
    fclose(tempFile);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (!encontrado) {
        printf("Produto n�o encontrado!\n");
    }
}

void cadastroProdutos() {
    int opcao = 0;
    do {
        printf("Menu de Cadastro de Produtos\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Alterar Pre�o de Venda\n");
        printf("4 - Adicionar Estoque\n");
        printf("5 - Apagar Produto\n");
        printf("6 - Retornar ao menu Principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
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
    } while (opcao != 6);
}
