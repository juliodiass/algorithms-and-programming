/*
7 -  Escreva uma função em C que receba um valor inteiro N, um float R e um float a1. N, R e A1 são a quantidade termos, a razão e o primeiro termo de uma progressão Geométrica (PG). 
Sua função deve gerar e retornar um vetor contento os N termos dessa PG. O vetor da PG deve ser alocado dinamicamente. 
Teste a sua função na função main().
*/
#include <stdio.h>
#include <stdlib.h>
float *calculo_pg(int N, float R, float a1){
    float *vet = calloc(N, sizeof(float));
    if(vet == NULL){
        printf("Nao foi possivel alocar a memoria!\n");
        return NULL;
    }
    for(int i = 0; i < N; i++){
        if(i == 0) 
            vet[i] = a1;
        else
            vet[i] = vet[i-1] * R;
    }
    return vet;
}
int main(){
    int N;
    float R, a1;
    printf("Digite a quantidade de termos: ");
    scanf("%d", &N);
    printf("Digite a razao: ");
    scanf("%f", &R);
    printf("Digite o primeiro termo: ");
    scanf("%f", &a1);

    float *vet = calculo_pg(N, R, a1);
    if(vet == NULL){
    return 0;
    }

    printf("A progressao e: ");
    for(int i = 0; i < N; i++){
        printf("%.f ", vet[i]);
    }
    free(vet);
    return 0;
}