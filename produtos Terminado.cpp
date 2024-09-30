#include <iostream>
#include <fstream>

using namespace std;

struct produto { //estrutura 
    int Id;
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) { //variavel do tipo inteiro que guarda quantos produtos ja foram adicionados , (&) significa que as mudanças na variavel dentro da funçao refletam fora dela 
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;    // info guardadas na posicao do array quantidadeAtual
    cout << "Preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade em estoque: ";
    cin >> produtos[quantidadeAtual].quantidade;
    quantidadeAtual++;
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) {  // Const e para nao ser alterado e usar so os valores
    for (int i = 0; i < quantidadeAtual; i++) {  // mostrar os produtos
        cout << "Produto " << i+1 << ":" << endl; // para numerar os produtos direito sempre que for mais do q 1 , produto 1,produto 2 ... e
        
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preço: " << produtos[i].preco << endl;
        cout << "Quantidade: " << produtos[i].quantidade << endl;
        cout << "-------------------------" << endl;
    }
}
void salvarProdutos(const produto produtos[], int quantidadeAtual) {
    ofstream file("produtos.txt", ios::app);  // Abrir o arquivo no modo de adicionar (append)

    if (!file.is_open()) {  // Verificar se o arquivo abriu corretamente
        cout << "Erro ao abrir o arquivo para salvar os produtos." << endl;
        return;
    }

    for (int i = 0; i < quantidadeAtual; i++) {
        file << i+1 << ",";
        file << i+1 << ":" << ",";
        file << produtos[i].nome << ",";
        file << produtos[i].preco << ",";
        file << produtos[i].quantidade << ",";
        file << "-------------------------" << endl;
    }

    file.close();  // Fechar o arquivo após a escrita
    cout << "Produtos salvos com sucesso no arquivo 'produtos.txt'!" << endl;
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
        cout << "4. Salvar Produtos em Arquivo" << endl;
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
                salvarProdutos(maxProdutos, quantidadeAtual);
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
