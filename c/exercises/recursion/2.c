/*
2 - Soma dos dígitos
Escreva uma função recursiva que receba um número inteiro positivo e retorne a soma de seus algarismos.
*/
#include <stdio.h>
int  mostrarsomadigito(int n){
    int soma;
    if(n == 1){
        return 1;
    }
    return (n % 10) + mostrarsomadigito(n / 10);
}
int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    int soma = mostrarsomadigito(n);
    printf("Soma: %d", soma);
    return 0;
}