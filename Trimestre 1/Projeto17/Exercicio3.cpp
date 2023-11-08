#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Classe Produto: Representa um produto com nome, preço e codigo.
class Produto {
private:
    string nome;
    double preco;
    int codigo;
public:
    // Construtor para inicializar os atributos
    Produto(string nome, double preco, int codigo) : nome(nome), preco(preco), codigo(codigo) {}

    // Métodos getters para obter os atributos privados
    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }

    int getCodigo() const {
        return codigo;
    }
};

// Estrutura para representar um item em estoque.
struct ItemEstoque {
    Produto produto;
    int quantidade;
};

// Classe Estoque: Controla a quantidade de cada produto no estoque.
class Estoque {
private:
    vector<ItemEstoque> itens;

public:
    // Adiciona um produto ao estoque com uma quantidade especificada
    void adicionarProduto(const Produto& produto, int quantidade) {
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade += quantidade;
                return;
            }
        }
        itens.push_back({produto, quantidade});
    }

    // Retorna a quantidade de um produto em estoque
    int getQuantidade(const Produto& produto) const {
        for (const auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                return item.quantidade;
            }
        }
        return 0;
    }

    // Remove uma quantidade de um produto do estoque
    void removerProduto(const Produto& produto, int quantidade) {
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade -= quantidade;
                if (item.quantidade < 0) {
                    item.quantidade = 0;
                }
                return;
            }
        }
    }
};

// Estrutura para representar um item no carrinho.
struct ItemCarrinho {
    Produto produto;
    int quantidade;
};

// Classe CarrinhoDeCompras: Representa um carrinho de compras.
class CarrinhoDeCompras {
private:
    vector<ItemCarrinho> itens;
    Estoque& estoqueRef;

public:
    // Construtor: inicializa a referência do estoque
    CarrinhoDeCompras(Estoque& estoque) : estoqueRef(estoque) {}

    // Adiciona um produto ao carrinho, considerando o estoque
    void adicionarProduto(const Produto& produto, int quantidade) {
        int disponivel = estoqueRef.getQuantidade(produto);
        if (disponivel < quantidade) {
            quantidade = disponivel;
        }
        
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade += quantidade;
                estoqueRef.removerProduto(produto, quantidade);
                return;
            }
        }
        itens.push_back({produto, quantidade});
        estoqueRef.removerProduto(produto, quantidade);
    }

    // Remove um produto do carrinho, devolvendo ao estoque
    void removerProduto(const Produto& produto, int quantidade) {
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade -= quantidade;
                if (item.quantidade < 0) {
                    item.quantidade = 0;
                }
                estoqueRef.adicionarProduto(produto, quantidade);
                return;
            }
        }
    }

    // Calcula o valor total do carrinho
    double calcularValorTotal() const {
        double total = 0.0;
        for(const auto& item : itens) {
            total += item.produto.getPreco() * item.quantidade;
        }
        return total;
    }

    // Esvazia o carrinho
    void esvaziarCarrinho() {
        itens.clear();
    }

    // Exibe os produtos e quantidades no carrinho
    void exibirCarrinho() const {
        cout << "Carrinho de Compras:" << endl;
        for(const auto& item : itens) {
            cout << "- " << item.produto.getNome() << " (" << item.produto.getPreco() << ") x " << item.quantidade << endl;
        }
    }
};

int main() {
    // Testando o sistema de cadastro de produtos
    Estoque estoque;
    
    Produto maca("Maca", 2.5, 101);
    Produto arroz("Arroz", 10.0, 102);
    Produto leite("Leite", 4.0, 103);
    Produto chocolate("Chocolate", 3.0, 104);

    estoque.adicionarProduto(maca, 50);
    estoque.adicionarProduto(arroz, 30);
    estoque.adicionarProduto(leite, 20);
    estoque.adicionarProduto(chocolate, 5); // Estoquedecalchocolate limitado a 5 unidades

    CarrinhoDeCompras carrinho(estoque);

    carrinho.adicionarProduto(maca, 3);
    carrinho.adicionarProduto(arroz, 2);
    carrinho.adicionarProduto(leite, 1);

    cout << "Valor total da compra: " << carrinho.calcularValorTotal() << endl; // 31.5

    carrinho.removerProduto(arroz, 1);

    cout << "Valor total apos remoção: " << carrinho.calcularValorTotal() << endl; // 21.5

    carrinho.esvaziarCarrinho();

    cout << "Valor total apos esvaziar o carrinho: " << carrinho.calcularValorTotal() << endl; // 0.0

    carrinho.adicionarProduto(chocolate, 10);
    //cout << "Quantidade de chocolates no carrinho: " << carrinho.getQuantidadeProduto(p4) << endl;

    carrinho.adicionarProduto(maca, 2);
    carrinho.adicionarProduto(arroz, 3);
    carrinho.adicionarProduto(leite, 1);
    carrinho.adicionarProduto(chocolate, 2);

    carrinho.exibirCarrinho();

    return 0;
}
