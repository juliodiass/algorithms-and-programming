/*
Redimensionando um vetor
Crie um programa em C que:
1. Aloque dinamicamente um vetor para armazenar 3 números inteiros, utilizando malloc().
2. Peça ao usuário para preencher as 3 posições.
3. Aumente o vetor para 5 posições, utilizando realloc().
4. Peça ao usuário para preencher as 2 novas posições.
5. Exiba todos os 5 números.
6. Libere a memória utilizando free().
*/
#include <stdio.h>
#include <stdlib.h>
int *alocarvetor(int qtd);
void exibirvetor(int *vet, int qtd);
int main(){
    int qtd = 3;
    int *vet = alocarvetor(qtd);
    if(vet == NULL){
        printf("A alocacao falhou!\n");
        return 1;
    }
    qtd = 5;
    exibirvetor(vet, qtd);
    free(vet);
    return 0;
}
int *alocarvetor(int qtd){
    int *vet = (int *) malloc(qtd * sizeof(int));
    if(vet == NULL){
        printf("A alocacao falhou!\n");
        return NULL;
    }
    printf("Digite %d numeros: ", qtd);
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    int *temp = (int * )realloc(vet, 5 * sizeof(int));
    if(temp == NULL){
        printf("A alocacao falhou!\n");
        return NULL;
    }
    vet = temp;
    printf("Digite + 2 numeros: ");
    for(int i = qtd; i < 5; i++){
        scanf("%d ", &vet[i]);
    }
    return vet;
}
void exibirvetor(int *vet, int qtd){
    printf("---Numeros cadastrados---\n");
    for(int i = 0; i < qtd; i++){
        printf("%d ", vet[i]);
    }
}