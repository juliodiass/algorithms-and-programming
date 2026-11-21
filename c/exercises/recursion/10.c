/*
Exercício 10 — Contar quantos dígitos tem um número
*/
#include <stdio.h>
int qtdDigitos(int N);
int main(){
    int N;
    printf("Digite um numero: ");
    scanf("%d", &N);
    int qtd = qtdDigitos(N);
    printf("Quantidade de digitos e: %d", qtd);
    return 0;
}
int qtdDigitos(int N){
    if(N == 0)
        return 0;
    return 1 + qtdDigitos(N/10);
}