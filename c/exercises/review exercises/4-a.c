/*
4) Considere o tipo struct vendedor, definido abaixo, e:  
(a) escreva o código de uma função em C que receba como parâmetro uma quantidade que será a quantidade de vendedores que se quer armazenar, declare um vetor contendo a quantidade recebida de elementos, 
leia os elementos do vetor e retorne um ponteiro para o vetor lido.
struct vendedor{
  char nome[20];
  int idade;
  float salario;
};
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char nome[20];
  int idade;
  float salario;
}vendedor;
vendedor *cadastrarVendedores(int N){
    vendedor *vet = (vendedor *) calloc(N, sizeof(vendedor));
    if(vet == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        return NULL;
    }

    for(int i = 0; i < N; i++){
        printf("# Vendedor %d\n", i+1);
        printf("Digite o nome do vendedor: ");
        scanf(" %19[^\n]", vet[i].nome);
        printf("Digite a idade do vendedor: ");
        scanf("%d", &vet[i].idade);
        printf("Digite o salario do vendedor: ");
        scanf("%f", &vet[i].salario);
        printf("\n");
    }
    return vet;
}
int main(){
    int N;
    printf("Digite a quantidade de vendedores a serem cadastrados: ");
    scanf("%d", &N);
    while(N <= 0){
        printf("Digite uma quantidade valida: ");
        scanf("%d", &N);
    }

    vendedor *vet = cadastrarVendedores(N);
    if (vet == NULL) {
    return 1;
    }
    
    for(int i = 0; i < N; i++){
        printf("# Vendedor %d\n", i+1);
        printf("Nome: %s\n", vet[i].nome);
        printf("Idade: %d\n", vet[i].idade);
        printf("Salario: %.2f\n", vet[i].salario);
        printf("\n");
    }
    free(vet);
    return 0;
}