/*
Uma loja de eletrônicos vende produtos que possuem diferentes formas de identificação e
precificação.
➢ Alguns produtos são importados e usam um código de barras alfanumérico (string de até
15 caracteres) e preço em dólar (float).
➢ Outros produtos são nacionais e usam um código SKU numérico (inteiro) e preço em reais
(inteiro representando os centavos, para evitar erros de precisão).
Como os dados nunca existirão ao mesmo tempo para o mesmo produto, a gerência da loja pediu
para otimizar o uso de memória do sistema rodando em um microcontrolador antigo.
Escreva um programa em Linguagem C que utilize uma union para armazenar os dados específicos
de cada tipo de produto, economizando espaço em memória.
Requisitos Técnicos:
Enumeração (enum Origin): Crie uma enumeração com as constantes NACIONAL e
IMPORTADO.
União (union ProductData): Crie uma união que possa armazenar:
1. Uma estrutura para o produto nacional: contendo o código SKU (int) e o preço em centavos
(int).
2. Uma estrutura para o produto importado: contendo o código de barras (char[16]) e o preço
em dólar (float).
Estrutura Principal (struct Product): Crie uma estrutura que junte:
✔ O nome do produto (char[30]).
✔ A tag de origem (enum Origin).
✔ A união (union ProductData).
Função Principal (main):
1) Cadastre pelo menos um produto nacional e um produto importado.
2) Exiba os dados de cada produto na tela. Ao exibir, use um bloco switch-case baseado na
enum para formatar a saída corretamente (exemplo: exibir o preço nacional com vírgula dividindo
os centavos, e o importado com o símbolo $).
*/
#include <stdio.h>
#include <string.h>
typedef enum{
    NACIONAL,
    IMPORTADO
}Origin;
typedef struct{
    int SKU;
    int preco;
}ProdutoNacional;
typedef struct{
    char code[16];
    float price;
}ProdutoImportado;
typedef union{
    ProdutoNacional nacional;
    ProdutoImportado importado;
}ProductData;
typedef struct{
    char nome[30];
    Origin origem;
    ProductData dados;
}Product;

void imprimirProduto(Product *produtos, int total){
    for(int i = 0; i < total; i++){
        switch(produtos[i].origem){
            case NACIONAL:
            printf("O produto %s (SKU %d) custa R$%d,%02d.\n", produtos[i].nome, produtos[i].dados.nacional.SKU, produtos[i].dados.nacional.preco / 100, produtos[i].dados.nacional.preco % 100);
            break;

            case IMPORTADO:
            printf("O produto %s (Codigo %s) custa $%.2f.\n", produtos[i].nome, produtos[i].dados.importado.code, produtos[i].dados.importado.price);
            break;
        }
    }
}
int main(){
    Product produtos[2];
    strcpy(produtos[0].nome, "Chinelo");
    produtos[0].origem = NACIONAL;
    produtos[0].dados.nacional.SKU = 10;
    produtos[0].dados.nacional.preco = 997;

    strcpy(produtos[1].nome, "Smartphone");
    produtos[1].origem = IMPORTADO;
    strcpy(produtos[1].dados.importado.code, "10001");
    produtos[1].dados.importado.price = 1297.99;

    imprimirProduto(produtos, 2);
}