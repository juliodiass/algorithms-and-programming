/*
Exercício 11 - Verificar se um número é palíndromo
*/
#include <stdio.h>
#include <math.h>
int verificarPalindromo(int N);
int qtdDigitos(int N);
int main(){
    int N;
    printf("Digite um numero: ");
    scanf("%d", &N);
    int resultado = verificarPalindromo(N);
    if(resultado == 1)
        printf("E palindromo!\n");
    else
        printf("Nao e palindromo!\n");
    return 0;
}
int verificarPalindromo(int N){
    if(N < 10)
        return 1;
    int divisor = pow(10, qtdDigitos(N) - 1);
    int primeiro = N / divisor;
    int ultimo = N % 10;
    if(primeiro != ultimo)
        return 0;
    N = (N % divisor) / 10;
    return verificarPalindromo(N);
}
int qtdDigitos(int N){
    if(N == 0)
        return 0;
    return 1 + qtdDigitos(N/10);
}