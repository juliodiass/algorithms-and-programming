/*
Seja a estrutura "Venda" abaixo.
typedef struct {
char data[9];
char nomeVendedor[30];
int qtdProdutos;
float valorTotal;
}Venda;
a) Escreva uma função em C para ler os valores para 10 vendas.
*/
#include <stdio.h>
typedef struct {
char data[9];
char nomeVendedor[30];
int qtdProdutos;
float valorTotal;
}Venda;
void registrarvendas(Venda *vendas, int qtd);
int main(){
    Venda vendas[10];
    registrarvendas(vendas, 10);
    return 0;
}
void registrarvendas(Venda *vendas, int qtd){
    printf("---REGISTRO DE VENDAS---\n");
    for(int i = 0; i < qtd; i++){
        printf("#VENDA %d\n", i+1);
        printf("Digite a data (XX/XX/XX): ");
        scanf(" %8[^\n]", vendas[i].data);
        printf("Digite o nome do vendedor: ");
        scanf(" %29[^\n]", vendas[i].nomeVendedor);
        printf("Digite a quantidade de produtos: ");
        scanf("%d", &vendas[i].qtdProdutos);
        printf("Digite o valor total: ");
        scanf("%f", &vendas[i].valorTotal);
        printf("\n");
    }
}
// SE FOSSE PARA A FUNÇÂO RETORNAR O VETOR
/*
Venda *registrarvendas(Venda *vendas, int qtd);
int main(){
    Venda vendas[10];
    Venda *resultado = registrarvendas(vendas, 10);
    
    return 0;
}
Venda *registrarvendas(Venda *vendas, int qtd){
    printf("---REGISTRO DE VENDAS---\n");
    for(int i = 0; i < qtd; i++){
        printf("#VENDA %d\n", i+1);
        printf("Digite a data (XX/XX/XX): ");
        scanf("%8[^\n]", vendas[i].data);
        printf("Digite o nome do vendedor: ");
        scanf("%29[^\n]", vendas[i].nomeVendedor);
        printf("Digite a quantidade de produtos: ");
        scanf("%d", &vendas[i].qtdProdutos);
        printf("Digite o valor total: ");
        scanf("%f", &vendas[i].valorTotal);
    }
    return vendas;
}
*/