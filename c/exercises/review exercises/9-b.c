/*
b) Escreva uma função em C que receba o vetor lido pela função do Item a) e a quantidade de
elementos do vetor. Sua função deve computar e retornar para a função chamadora: a data da venda
com o maior valor, o nome do vendedor que vendeu a maior quantidade de produtos em uma única
venda, o valor médio de todas as vendas.
*/
#include <stdio.h>
#include <string.h>
typedef struct {
char data[9];
char nomeVendedor[30];
int qtdProdutos;
float valorTotal;
}Venda;
typedef struct {
    char dataMaiorVenda[9];
    char vendedorMaiorQtd[30];
    float mediaVendas;
} Resultado;

void registrarvendas(Venda *vendas, int qtd);
Resultado calcularResultados(Venda *vendas, int qtd);
int main(){
    Venda vendas[10];
    registrarvendas(vendas, 10);
    Resultado resultado = calcularResultados(vendas, 10);
    printf("\n--- RESULTADOS ---\n");
    printf("Data da maior venda: %s\n", resultado.dataMaiorVenda);
    printf("Vendedor com maior quantidade: %s\n", resultado.vendedorMaiorQtd);
    printf("Media das vendas: R$ %.2f\n", resultado.mediaVendas);
    return 0;
}
void registrarvendas(Venda *vendas, int qtd){
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
}

Resultado calcularResultados(Venda *vendas, int qtd) {
    Resultado resultado;

    int maiorValor = 0;
    int maiorQtd = 0;
    float soma = 0;

    for(int i = 0; i < qtd; i++) {

        // Venda com maior valor total
        if(vendas[i].valorTotal > vendas[maiorValor].valorTotal) {
            maiorValor = i;
        }

        // Venda com maior quantidade de produtos
        if(vendas[i].qtdProdutos > vendas[maiorQtd].qtdProdutos) {
            maiorQtd = i;
        }

        // Soma dos valores para calcular a média
        soma += vendas[i].valorTotal;
    }

    strcpy(resultado.dataMaiorVenda, vendas[maiorValor].data);

    strcpy(resultado.vendedorMaiorQtd, vendas[maiorQtd].nomeVendedor);

    resultado.mediaVendas = soma / qtd;

    return resultado;
}