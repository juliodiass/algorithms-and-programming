/*
Questao 1
1 - Escreva um programa em C que declare, leia e mostre os elementos de um vetor de n inteiros. 
A quantidade n do vetor deve ser um valor passado pelo usuario do seu programa e alocada dinamicamente. 
*/
#include <stdio.h>
#include <stdlib.h>
void receber(int *vet, int n){
    printf("Digite %d numeros: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
}
void imprimir(int *vet, int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", vet[i]);
    }
}
int main(){
    int *vet, n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vet = malloc(n * sizeof(int));
    if(vet == NULL){
        printf("Erro ao alocar memoria!\n");
        return 0;
    }
    receber(vet, n);
    imprimir(vet, n);
    free(vet);
    return 0;
}