#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct produto {
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

void exibirProdutos(const produto produtos[], int quantidadeAtual) {
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "Produto " << i + 1 << ":" << endl;
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

void alterarProduto(produto produtos[], int quantidadeAtual) {
    int indice;
    cout << "Digite o índice do produto a alterar (1 a " << quantidadeAtual << "): ";
    cin >> indice;
    if (indice < 1 || indice > quantidadeAtual) {
        cout << "Índice inválido." << endl;
        return;
    }
    indice--; // Ajustar para índice zero baseado
    cout << "Novo nome do produto: ";
    cin >> produtos[indice].nome;
    cout << "Novo preço do produto: ";
    cin >> produtos[indice].preco;
    cout << "Nova quantidade em estoque: ";
    cin >> produtos[indice].quantidade;
}

void eliminarProduto(produto produtos[], int& quantidadeAtual) {
    int indice;
    cout << "Digite o índice do produto a eliminar (1 a " << quantidadeAtual << "): ";
    cin >> indice;
    if (indice < 1 || indice > quantidadeAtual) {
        cout << "Índice inválido." << endl;
        return;
    }
    indice--; // Ajustar para índice zero baseado
    for (int i = indice; i < quantidadeAtual - 1; i++) {
        produtos[i] = produtos[i + 1]; // Deslocar produtos
    }
    quantidadeAtual--; // Diminuir a quantidade atual de produtos
}

void salvarProdutos(const produto produtos[], int quantidadeAtual) {
    ofstream outFile("produtos.txt");
    if (outFile) {
        for (int i = 0; i < quantidadeAtual; i++) {
            outFile << produtos[i].nome << endl;
            outFile << produtos[i].preco << endl;
            outFile << produtos[i].quantidade << endl;
        }
        outFile.close();
        cout << "Produtos salvos com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvar." << endl;
    }
}

void carregarProdutos(produto produtos[], int& quantidadeAtual) {
    ifstream inFile("produtos.csv");
    if (inFile) {
        while (inFile >> produtos[quantidadeAtual].nome) {
            inFile >> produtos[quantidadeAtual].preco;
            inFile >> produtos[quantidadeAtual].quantidade;
            quantidadeAtual++;
        }
        inFile.close();
        cout << "Produtos carregados com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para carregar." << endl;
    }
}

int main() {
    produto maxProdutos[100];
    int quantidadeAtual = 0;
    int escolha;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do stock da Loja" << endl;
        cout << "4. Alterar Produto" << endl;
        cout << "5. Eliminar Produto" << endl;
        cout << "6. Salvar Produtos" << endl;
        cout << "7. Carregar Produtos" << endl;
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
            case 4:
                alterarProduto(maxProdutos, quantidadeAtual);
                break;
            case 5:
                eliminarProduto(maxProdutos, quantidadeAtual);
                break;
            case 6:
                salvarProdutos(maxProdutos, quantidadeAtual);
                break;
            case 7:
                carregarProdutos(maxProdutos, quantidadeAtual);
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
