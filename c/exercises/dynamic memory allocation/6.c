/*
6 - Escreva uma função em C que receba um valor inteiro N e retorne um vetor contendo os N primeiros números primos que existem. 
O vetor de primos deve ser alocado dinamicamente. Teste a sua função na função main().
*/
#include <stdio.h>
#include <stdlib.h>
int *calculoprimo(int n){
    int *vet = malloc(n * sizeof(int));
    int qtd_primos = 0;

    for(int i = 2; qtd_primos < n; i++){
        int qtd = 0;

        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                qtd++;
            }
        }
        if(qtd == 2){
            vet[qtd_primos] = i;
            qtd_primos++;
        }
    }
    return vet;
}
int main(){
    int n, *vet;
    printf("Digite um numero: ");
    scanf("%d", &n);
    vet = calculoprimo(n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    free(vet);
    return 0;
}