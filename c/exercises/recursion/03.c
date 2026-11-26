/*
3 - Faça uma função recursiva em C que receba um número inteiro positivo n e retorne o seu fatorial.
*/
#include <stdio.h>
int calculoFatorial(int N);
int main(){
    int N;
    printf("Digite um numero: ");
    scanf("%d", &N);
    int fatorial = calculoFatorial(N);
    printf("%d! = %d", N, fatorial);
    return 0;
}
int calculoFatorial(int N){
    if(N == 1)
        return 1;
    return N * calculoFatorial(N - 1);
}