#include <iostream>

using namespace std;

struct produto { //estrutura 
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) { //variavel do tipo inteiro que guarda quantos produtos ja foram adicionados , (&) significa que as mudanças na variavel dentro da funçao refletam fora dela 
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
    cout << "Preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade em estoque: ";
    cin >> produtos[quantidadeAtual].quantidade;
    quantidadeAtual++;
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) { 
    for (int i = 0; i < quantidadeAtual; i++) {  // ciclo for para numerar os produtos direito sempre que for mais do q 1 , produto 1,produto 2 ...
        cout << "Produto " << i+1 << ":" << endl;
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preço: " << produtos[i].preco << endl;
        cout << "Quantidade: " << produtos[i].quantidade << endl;
        cout << "-------------------------" << endl;
    }
}

float calcularValorTotal(const produto produtos[], int quantidadeAtual) {
    float valorTotal = 0.0;
    for (int i = 0; i < quantidadeAtual; i++) {  
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return valorTotal; //inicializa a variavel do valor total como 0 e passa pelo array de produtos multiplicando o preco pela quantidade
}

int main() {
    produto maxProdutos[100]; // maximo de protudos 
    int quantidadeAtual = 0; // aramazena a quantidade de protudos no stock
    int escolha;

    do {    // percorre o codigo ate a escolha ser o 0
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
