/*
4 - Potência usando recursividade
Crie uma função recursiva em C que receba dois inteiros, base e expoente, e retorne o resultado da potência.
*/
#include <stdio.h>
int potencia(int base, int expoente){
    if(expoente == 0)
        return 1;
    return base * potencia(base, expoente - 1);
}
int main(){
    int base, expoente;
    printf("Digite a base e o seu expoente: ");
    scanf("%d %d", &base, &expoente);
    int resultado = potencia(base, expoente);
    printf("%d^%d = %d", base, expoente, resultado);
    return 0;
}