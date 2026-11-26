/*
1 - Escreva uma função recursiva em C que receba um número inteiro positivo n e retorne a soma de todos os números inteiros de 1 até n.
*/
#include <stdio.h>
int  mostrarsoma(int n){
    if(n == 1){
        return 1;
    }
    return n + mostrarsoma(n-1);
}
int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    int soma = mostrarsoma(n);
    printf("Soma: %d", soma);
    return 0;
}