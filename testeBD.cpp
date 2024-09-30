#include <iostream>
#include <fstream>

using namespace std;

struct produto { // Estrutura de produto
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) {
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
    cout << "Preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade em estoque: ";
    cin >> produtos[quantidadeAtual].quantidade;
    quantidadeAtual++;
}

void salvarProduto(produto produtos[], int quantidadeAtual) {
    char escolha;
    cout << "Deseja criar um novo ficheiro (N) ou utilizar o ficheiro existente (E)? ";
    cin >> escolha;
    int lastId = 0;

    ofstream file;
    if (escolha == 'N' || escolha == 'n') {
        file.open("produtos.txt", ios::out);  // Sobrescreve o arquivo
        cout << "Novo ficheiro criado, sobrescrevendo o anterior." << endl;
    } else if (escolha == 'E' || escolha == 'e') {
        file.open("produtos.txt", ios::app);  // Abre o arquivo no modo de adição
        cout << "Utilizando o ficheiro existente, adicionando ao final." << endl;
    } else {
        cout << "Opção inválida! O ficheiro não foi modificado." << endl;
        return;
    }

    if (!file) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    for (int i = 0; i < quantidadeAtual; i++) {
        int id = ++lastId; // Incrementa o ID para cada produto
        file << id << "," << produtos[i].nome << "," << produtos[i].quantidade << "," 
             << produtos[i].preco << endl;
    }
    
    

    
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) { 
    for (int i = 0; i < quantidadeAtual; i++) {
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
    return valorTotal;
}

int main() {
    produto maxProdutos[100]; // Máximo de produtos
    int quantidadeAtual = 0; // Armazena a quantidade de produtos no stock
    int escolha;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do stock da Loja" << endl;
        cout << "0. Sair" << endl;
        cin >> escolha;

        switch (escolha) {
            case 1:
                adicionarProduto(maxProdutos, quantidadeAtual);
                salvarProduto(maxProdutos, quantidadeAtual);
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
                cout << "Escolha outra opção." << endl; 
        }
    } while (escolha != 0);

    return 0;
}
