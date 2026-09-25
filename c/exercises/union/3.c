/*
Questão 3:
Suponha que você esteja desenvolvendo um sistema para uma loja de eletrônicos que vende
diferentes tipos de produtos: smartphones, laptops e smartwatches. Cada produto tem diferentes
características que precisam ser armazenadas, como o tamanho da tela, a capacidade de
armazenamento e a duração da bateria. Neste exercício, você usará unions para criar uma estrutura
de dados flexível para armazenar informações sobre esses produtos.
Crie uma union chamada InfoProduto que contenha três campos: tamanhoTela (float),
capacidadeArmazenamento (int) e duracaoBateria (int).
Crie uma enumeração chamada TipoProduto com os seguintes valores: SMARTPHONE, LAPTOP
e SMARTWATCH.
Crie uma struct chamada Produto que contenha dois campos: tipo (do tipo TipoProduto) e info (do
tipo InfoProduto).
Escreva uma função chamada imprimirProduto que recebe um ponteiro para uma struct Produto
como argumento. Esta função deve imprimir os detalhes do produto, incluindo o tipo (usando uma
declaração de switch-case para mostrar "Smartphone", "Laptop" ou "Smartwatch") e os detalhes
específicos do produto (tamanho da tela, capacidade de armazenamento e duração da bateria).
No programa principal, declare três variáveis do tipo Produto e inicialize-as com diferentes tipos de
produtos e informações específicas.
Chame a função imprimirProduto para imprimir os detalhes de cada um dos produtos.
*/
#include <stdio.h>
typedef union {
    float tamanhoTela;
    int capacidadeArmazenamento;
    int duracaoBateria;
} InfoProduto;

typedef enum {
    SMARTPHONE,
    LAPTOP,
    SMARTWATCH
} TipoProduto;

typedef struct {
    TipoProduto tipo;
    InfoProduto info;
} Produto;

void imprimirProduto(Produto *p){
    switch(p->tipo){
        case SMARTPHONE:
        printf("Smartphone:\n");
        printf("Tamanho da tela: %.1f polegadas\n", p->info.tamanhoTela);
        break;

        case LAPTOP:
        printf("Laptop:\n");
        printf("Capacidade de armazenamento: %d GB\n", p->info.capacidadeArmazenamento);
        break;

        case SMARTWATCH:
        printf("Smartwatch:\n");
        printf("Duracao da bateria: %d horas\n", p->info.duracaoBateria);
        break;
    }
}
int main(){
    Produto celular;
    Produto notebook;
    Produto relogio;

    celular.tipo = SMARTPHONE;
    celular.info.tamanhoTela = 6.5;

    notebook.tipo = LAPTOP;
    notebook.info.capacidadeArmazenamento = 512;

    relogio.tipo = SMARTWATCH;
    relogio.info.duracaoBateria = 48;

    imprimirProduto(&celular);
    printf("\n");
    imprimirProduto(&notebook);
    printf("\n");
    imprimirProduto(&relogio);
    return 0;
}