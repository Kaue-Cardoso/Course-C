#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char login[13];
    char senha[9];
    int tipo;
} Usuario;


//Inicio Menu Principal ---------------------------------
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
int cadastros()
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
            if (cadastroUsuarios() == 1) return 1;
            break;
        case 2:
            printf("Fun��o Cadastrar ainda n�o implementada.\n");
            //cadastroClientes();
            break;
        case 3:
            printf("Fun��o Cadastrar ainda n�o implementada.\n");
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
// CADASTRO DE USUARIOS ------------------
int cadastroUsuarios()
{
    int opcao;
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
    FILE *file = fopen("cadastroClientes.txt", "a");

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
    FILE *file = fopen("cadastroClientes.txt", "r");

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
int validarAdministrador(const char *login, const char *senha) {
    char linha[256]; // Buffer para armazenar cada linha lida do arquivo
    FILE *file = fopen("cadastroClientes.txt", "r"); // Abre o arquivo para leitura

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








//Fim Menu Principal ---------------------
