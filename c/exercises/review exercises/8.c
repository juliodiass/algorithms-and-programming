/*
Crie um programa em C que permita ao usuário escolher a quantidade de elementos de um vetor e depois redimensioná-lo.
Requisitos
1. Pergunte quantos números o usuário deseja armazenar inicialmente.
2. Aloque a memória utilizando malloc().
3. Solicite os valores e preencha o vetor.
4. Pergunte para quantas posições o usuário deseja redimensionar o vetor.
5. Utilize realloc() para alterar o tamanho.
6. Se o vetor aumentar, solicite os valores das novas posições.
7. Se diminuir, mantenha somente os elementos que couberem no novo tamanho.
8. Exiba o vetor atualizado.
9. Libere a memória com free().
*/
#include <stdio.h>
#include <stdlib.h>
int *cadastrarnumeros(int qtd);
int *novovet(int *vet, int newqtd, int qtd);
void exibirvetor(int *vet, int newqtd);
int main(){
    int qtd;
    do{
    printf("Digite quantos numeros deseja adicionar: ");
    scanf("%d", &qtd);
    }while(qtd <= 0);
    int *vet = cadastrarnumeros(qtd);
    if(vet == NULL){
        printf("A alocacao falhou!\n");
        return 1;
    }
    int newqtd;
    do{
        printf("Para quantas posicoes deseja redimensionar: ");
        scanf("%d", &newqtd);
    }while(newqtd <= 0);
    vet = novovet(vet, newqtd, qtd);
    if(vet == NULL){
      return 1;
    }
    exibirvetor(vet, newqtd);
    free(vet);
    return 0;
}
int *cadastrarnumeros(int qtd){
    int *vet = (int *) malloc(qtd * sizeof(int));
    if(vet == NULL){
        printf("A alocacao falhou!\n");
        return NULL;
    }
    printf("---CADASTRO DE NUMEROS---\n");
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    return vet;
}
int *novovet(int *vet, int newqtd, int qtd){
    int *temp = (int *) realloc(vet, newqtd * sizeof(int));
    if(temp == NULL){
        printf("A alocacao falhou!\n");
        free(vet);
        return NULL;
    }
    vet = temp;
    printf("---REDIMENSIONANDO O VETOR---\n");
    if(newqtd > qtd){
        printf("Digite os novos %d numeros: ", newqtd - qtd);
        for(int i = qtd; i < newqtd; i++){
            scanf("%d", &vet[i]);
        }
    }
    return vet;
}
void exibirvetor(int *vet, int newqtd){
    printf("---VALORES ARMAZENADOS---\n");
    for(int i = 0; i < newqtd; i++){
        printf("%d ", vet[i]);
    }
}