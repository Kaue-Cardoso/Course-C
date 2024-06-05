#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[30],sobrenome[50], cpf[30], local_nascimento[40];
    printf("Cadastro de Soldados\nInsira os Seguintes dados a Seguir: Nome, Sobrenome, CPF e Local de Nascimento\n");
    printf(" Nome: ");
    scanf("%s", &nome);
    printf(" Sobrenome: ");
    scanf("%s", &sobrenome);
    printf(" CPF: ");
    scanf("%s", &cpf);
    printf(" Local de Nascimento: ");
    scanf("%s", &local_nascimento);
    printf("\n\nDados do Recruta: \nNome: %s\nSobrenome: %s\nCPF: %s\nLocal de Nascimento: %s\n", nome,sobrenome, cpf,local_nascimento);
    return 0;
}
