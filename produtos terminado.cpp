#include <iostream>

using namespace std;

struct produto {
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) { // funcao para adicionar produtos
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome; //o array de produtos guarda as varias cenas da estrutura (nome)
    cout << "Preço do produto: ";
    cin >> produtos[quantidadeAtual].preco; // (preco)
    cout << "Quantidade em estoque: ";
    cin >> produtos[quantidadeAtual].quantidade; // (quantidade)
    quantidadeAtual++;
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) { // funcao para mostrar os produtos
    for (int i = 0; i < quantidadeAtual; i++) { // ciclo for para smpre q exibir mais que um produto numeralos 
        cout << "Produto " << i+1 << ":" << endl;
        cout << "Nome: " << produtos[i].nome << endl; // mostrar o nome 
        cout << "Preço: " << produtos[i].preco << endl; // mostrar o preco
        cout << "Quantidade: " << produtos[i].quantidade << endl; // mostrar quantidade
        cout << "-------------------------" << endl;
    }
}

float calcularValorTotal(const produto produtos[], int quantidadeAtual) { 
    float valorTotal = 0.0;  
    for (int i = 0; i < quantidadeAtual; i++) {  // inicia com a variavel para o total como 0 e precorre o array de produtos
        valorTotal += produtos[i].preco * produtos[i].quantidade; // multiplicando  o preço pela quantidade e soma o valor
    }
    return valorTotal; // retorna o valor do stock
}

int main() {
    produto maxProdutos[100]; // maximiza a quantidade dos produtos que podemos adicionar que é 100
    int quantidadeAtual = 0; //armazena o numero de produtos no stock
    int escolha;

    do {  // precorre o codigo enquanto a escolha for difrente ou = 0
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do stock da Loja" << endl;
        cout << "0. Sair" << endl;
        cin >> escolha;

        switch (escolha) {
            case 1:
                adicionarProduto(maxProdutos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(maxProdutos, quantidadeAtual);
                break;
            case 3:
                cout << "Valor total do stock: " << calcularValorTotal(maxProdutos, quantidadeAtual) << endl;
                break;
            case 0:
                cout << "A sair..." << endl;
                break;
            default:
                cout << "Escolha outra opcao." << endl;
        }
    } while (escolha != 0);

    return 0;
}
