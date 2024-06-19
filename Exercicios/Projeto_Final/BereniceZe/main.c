#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    int opcao=1;
    do{
        opcao = 0;
        system("cls");
        menuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                cadastros();
                break;
            case 2:
                printf("Funcao nao implementada");
                //vendas();
                break;
            case 3:
                printf("Funcao nao implementada");
                //aberturaDeCaixa();
                break;
            case 4:
                printf("Funcao nao implementada");
                //fechamentoDeCaixa();
                break;
            case 5:
                printf("Funcao nao implementada");
                //relatorios();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcaoo invalida. Tente novamente.\n");
        }
        if (opcao != 6) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Espera pelo Enter
            getchar(); // Captura o Enter adicional
        }


    } while(opcao != 6);
    return 0;
}






































/*
--Tela Inicial-------------------
Menu Principal
1. Cadastros
2. Vendas
3. Abertura de Caixa
4. Fechamento de Caixa
5.Relatórios
7.Sair
---------------------------------
OBS: Dona Berê percebeu as vantagens de arquivar os clientes antigos e
novos, ofertar novos produtos e descontinuar outros, deseja vender conforme a variação dos
dias da semana. Por exemplo: sexta e segunda são dias com volume de vendas atípico. A
empresária deseja que tudo seja flexível!

--Tela Cadastros-------------------
1. CADASTROS
1.1 . Cadastro de usuários
1.2. Cadastro de Clientes
1.3 Cadastro de Produtos
1.4 Cadastro de Categoria
1.3 Retornar ao Menu Principal
---------------------------------
OBS 1.1: Ao cadastrar os usuários, a Dona Berê deseja guardar: login( user >= 8 e <=12 caracteres) e
senha (password >= 6 e <=8 caracteres) e tipo.
O tipo terá guardado dois valores: 1. Administrador do sistema. 2. Usuário.
Regra de negócio: As operações de Sangria, Abertura de Caixa e Fechamento de Caixa devem
validar se o usuário logado é do tipo 1. Caso não seja, o sistema deve solicitar um login e senha
de administrador, após essa validação, a opção é liberada.

OBS 1.2: Ao cadastrar os clientes, a Dona Berê deseja guardar: um código para cada cliente, o nome
completo, o nome social (atendimento à legislação de respeito à diversidade), o CPF, a
rua/número , o bairro, celular/Whats. Ela não sabe quantos clientes terá. Por isso , deseja
poder, a qualquer momento, cadastrar um novo cliente

OBS 1.3: Ao cadastrar os produtos, a Dona Berê deseja guardar: um código para o produto, a descrição
do produto, a categoria (Alimento, Material de Limpeza, Panificação), preço de compra, a
margem de lucro (em percentual a ser calculado como acréscimo ao valor da compra gerando
o valor da venda), preço de venda (deseja que seja calculado no ato da venda em decorrência
da necessidade de modificar a margem de lucro ao longo do tempo), quantidade em estoque e
o estoque mínimo

Regras aos Produtos:
1. No ato da venda, caso o estoque mínimo tenha sido alcançado, dona Berê
deseja receber uma mensagem de alerta do sistema;
2. No ato da venda, caso a quantidade de itens a serem comprado pelo cliente
seja maior que a quantidade presente em estoque dona Berê deseja receber
uma mensagem de alerta do sistema. Por exemplo: “Você deseja vender 4
produtos. Há somente 3 em estoque! Continuar (s/n)?;
3. No ato da venda, não é possível vender produtos com estoque ZERADO. dona
Berê deseja receber uma mensagem de alerta do sistema quando isso ocorrer.

*/
