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
5.Relat�rios
7.Sair
---------------------------------
OBS: Dona Ber� percebeu as vantagens de arquivar os clientes antigos e
novos, ofertar novos produtos e descontinuar outros, deseja vender conforme a varia��o dos
dias da semana. Por exemplo: sexta e segunda s�o dias com volume de vendas at�pico. A
empres�ria deseja que tudo seja flex�vel!

--Tela Cadastros-------------------
1. CADASTROS
1.1 . Cadastro de usu�rios
1.2. Cadastro de Clientes
1.3 Cadastro de Produtos
1.4 Cadastro de Categoria
1.3 Retornar ao Menu Principal
---------------------------------
OBS 1.1: Ao cadastrar os usu�rios, a Dona Ber� deseja guardar: login( user >= 8 e <=12 caracteres) e
senha (password >= 6 e <=8 caracteres) e tipo.
O tipo ter� guardado dois valores: 1. Administrador do sistema. 2. Usu�rio.
Regra de neg�cio: As opera��es de Sangria, Abertura de Caixa e Fechamento de Caixa devem
validar se o usu�rio logado � do tipo 1. Caso n�o seja, o sistema deve solicitar um login e senha
de administrador, ap�s essa valida��o, a op��o � liberada.

OBS 1.2: Ao cadastrar os clientes, a Dona Ber� deseja guardar: um c�digo para cada cliente, o nome
completo, o nome social (atendimento � legisla��o de respeito � diversidade), o CPF, a
rua/n�mero , o bairro, celular/Whats. Ela n�o sabe quantos clientes ter�. Por isso , deseja
poder, a qualquer momento, cadastrar um novo cliente

OBS 1.3: Ao cadastrar os produtos, a Dona Ber� deseja guardar: um c�digo para o produto, a descri��o
do produto, a categoria (Alimento, Material de Limpeza, Panifica��o), pre�o de compra, a
margem de lucro (em percentual a ser calculado como acr�scimo ao valor da compra gerando
o valor da venda), pre�o de venda (deseja que seja calculado no ato da venda em decorr�ncia
da necessidade de modificar a margem de lucro ao longo do tempo), quantidade em estoque e
o estoque m�nimo

Regras aos Produtos:
1. No ato da venda, caso o estoque m�nimo tenha sido alcan�ado, dona Ber�
deseja receber uma mensagem de alerta do sistema;
2. No ato da venda, caso a quantidade de itens a serem comprado pelo cliente
seja maior que a quantidade presente em estoque dona Ber� deseja receber
uma mensagem de alerta do sistema. Por exemplo: �Voc� deseja vender 4
produtos. H� somente 3 em estoque! Continuar (s/n)?;
3. No ato da venda, n�o � poss�vel vender produtos com estoque ZERADO. dona
Ber� deseja receber uma mensagem de alerta do sistema quando isso ocorrer.

*/
