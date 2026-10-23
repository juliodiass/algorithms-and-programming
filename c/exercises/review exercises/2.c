/*
2) Seja a struct Imóveis com: Código, valor, área total. Crie uma função que receba como argumento um valor n, que será a quantidade de imóveis, 
declare uma vetor com n imóveis, leia os valores para o vetor e retorne o vetor lido.
*/
#include <stdio.h>
typedef struct{
    int codigo;
    int valor;
    int areaTotal;
}Imoveis;
void cadastrarimoveis(Imoveis vet[], int n){
    for(int i = 0; i < n; i++){
        printf("# Imovel %d\n", i+1);
        printf("Codigo: ");
        scanf("%d", &vet[i].codigo);
        printf("Valor: ");
        scanf("%d", &vet[i].valor);
        printf("Area total: ");
        scanf("%d", &vet[i].areaTotal);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Digite a quantidade de imoveis a serem cadastrados: ");
    scanf("%d", &n);

    Imoveis vet[n];
    cadastrarimoveis(vet, n);

    for(int i = 0; i < n; i++){
        printf("# Imovel %d\n", i+1);
        printf("Codigo: %d\n", vet[i].codigo);
        printf("Valor: %d\n", vet[i].valor);
        printf("Area total: %d\n", vet[i].areaTotal);
    }
    return 0;
}