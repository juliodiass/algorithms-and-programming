/*
Crie um programa em C que cadastre um produto e calcule seu preço final.
1. Crie uma struct Produto
Ela deve possuir:
- nome: vetor de caracteres de 50 posições.
- preco: float.
- quantidade: inteiro.
2. Crie as seguintes funções
Função	O que deve fazer
cadastrarProduto()	Retornar uma struct Produto preenchida.
calcularTotal()	Receber o preço e a quantidade e retornar o valor total (float).
mostrarProduto()	Receber um ponteiro para Produto e exibir seus dados.

3. Na main()
1. Declare uma variável Produto.
2. Utilize cadastrarProduto() para preencher essa variável.
3. Utilize calcularTotal() para calcular o preço total.
4. Utilize mostrarProduto() para exibir os dados.
5. Mostre também o valor total da compra.
Regras
- Declare os protótipos antes da main().
- Implemente as funções depois da main().
- Utilize return quando necessário.
- Utilize void quando a função não precisar retornar nada.
- Na função mostrarProduto(), utilize -> para acessar os campos.
*/
#include <stdio.h>
typedef struct{
    char nome[50];
    float preco;
    int qtd;
}Produto;
Produto cadastrarProduto();
float calcularTotal(float preco, int qtd);
void mostrarProduto(Produto *produto, float valorTotal);
int main(){
    Produto produto = cadastrarProduto();
    float valorTotal = calcularTotal(produto.preco, produto.qtd);
    mostrarProduto(&produto, valorTotal);
    return 0;
}
Produto cadastrarProduto(){
    Produto produto;
    printf("Digite o nome do produto: ");
    scanf(" %49[^\n]", produto.nome);
    printf("Digite o nome do produto: ");
    scanf("%f", &produto.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto.qtd);
    printf("\n");
    return produto;
}
float calcularTotal(float preco, int qtd){
    float total = preco * qtd;
    return total;
}
void mostrarProduto(Produto *produto, float valorTotal){
    printf("Nome: %s\n", produto->nome);
    printf("Preco: %.2f\n", produto->preco);
    printf("Qtd: %d\n", produto->qtd);
    printf("Valor total em produtos: %.2f", valorTotal);
}