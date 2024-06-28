#ifndef FUNCOES_H
#define FUNCOES_H

//Menu Principal----------
void menuPrincipal();
void cadastros();
void vendas();
void aberturaDeCaixa();
void fechamentoDeCaixa();
void relatorios();

int validarAdministrador();

//CadastroUsuarios
void cadastroUsuarios();
void cadastrarUsuario();
void listarUsuarios();
void removerUsuario();

//CadastroClientes
void cadastroClientes();
void cadastrarCliente();
void listarClientes();

//CadastroProdutos
void cadastrarProduto();
void listarProdutos();
void alterarPrecoVenda();
void adicionarEstoque();
void apagarProduto();
//void calcularMargemLucro(Produto *produto);


int gerarIdUnicoCompra();
void cadastrarNovaVenda();
void comprasEmAberto();
void finalizarCompra();
void vendas();
void listarVendasFinalizadas();






#endif // FUNCOES_H
