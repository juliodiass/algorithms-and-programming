/*
Questão 08 -
Escreva uma função em C chamada cadastrarProdutos que receba como parâmetro um valor inteiro N, correspondente à quantidade de produtos que serão cadastrados.
Cada produto deverá possuir uma estrutura com os seguintes dados:
- nome — string de até 30 caracteres;
- codigo — inteiro;
- preco — float.
A função deverá alocar dinamicamente um vetor com N produtos, ler os dados dos produtos informados pelo usuário e retornar um ponteiro para esse vetor.
O cabeçalho da função deverá ser:
Produto* cadastrarProdutos(int N);
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[30];
    int codigo;
    float preco;
}Produto;
Produto* cadastrarProdutos(int N){
    Produto *produtos = (Produto *) calloc(N, sizeof(Produto));
    for(int i = 0; i < N; i++){
        printf("Digite os dados do produto %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %29[^\n]", produtos[i].nome);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("\n");
    }

    return produtos;
}
int main(){
    int N;
    printf("Digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &N);
    Produto* produtos = cadastrarProdutos(N);
    for(int i = 0; i < N; i++){
        printf("Dados do produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Preco: R$%.2f\n", produtos[i].preco);
        printf("\n");
    }

    free(produtos);
    return 0;
}
