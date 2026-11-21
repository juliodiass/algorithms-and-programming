/*
Exercício 9 — Contagem regressiva
Crie uma função recursiva que receba um número inteiro e imprima uma contagem regressiva até zero.
*/
#include <stdio.h>
void contagemRegressiva(int N);
int main(){
    int N;
    printf("Digite um numero: ");
    scanf("%d", &N);
    contagemRegressiva(N);

    return 0;
}
void contagemRegressiva(int N){
    printf("%d ", N);
    if(N == 0){
        return;
    }
    return contagemRegressiva(N-1);
}