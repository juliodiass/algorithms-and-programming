/*
Exercício 1 — Aumentando um vetor
Objetivo: criar um vetor dinâmico com 3 números e depois aumentá-lo para 5 posições usando realloc().

O programa deve:
1. Alocar espaço para 3 inteiros usando malloc().
2. Ler os 3 números digitados pelo usuário.
3. Usar realloc() para aumentar o vetor para 5 inteiros.
4. Guardar o resultado da realocação em um ponteiro temporário.
5. Se a realocação funcionar, atualizar o ponteiro original e ler mais 2 números.
6. Exibir os 5 números e liberar a memória.
*/
#include <stdio.h>
#include <stdlib.h>
int *alocarvetor(int N) {
    int *vet = (int *) malloc(N * sizeof(int));

    printf("Digite 3 numeros inteiros: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }
    return vet;
}
int *realocarvetor(int *vet, int n){
    int *temp = (int*)realloc(vet, 5 * sizeof(int));
    if(temp == 0){
        printf("A realocacao falhou!\n");
        return NULL;
    }
    else{
        vet = temp;
    }
    printf("Digite mais 2 numeros: ");
    for(int i = 0; i < 2; i++){
        scanf("%d", &temp[i+n]);
    }
    return vet;
}
int main(){
    int N = 3;
    int *vet = alocarvetor(N);
    vet = realocarvetor(vet, N);
    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
    free(vet);
}