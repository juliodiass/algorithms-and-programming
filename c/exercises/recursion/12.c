/*
Exercicio 12 - Faça uma função recursiva chamada multiplicacao() que receba dois números inteiro positivo
n1 e n2 como argumento e retorne a multiplicação dos dois números inteiros. Por exemplo, se
a função receber n1 = 3 e n2 = 4, deverá retornar 12, pois 12 = 3+3+3+3.
*/
#include <stdio.h>
int multiplicacao(int n1, int n2);
int main(){
    int n1, n2;
    printf("Digite 2 numeros: ");
    scanf("%d %d", &n1, &n2);
    int resultado = multiplicacao(n1, n2);
    printf("O resultado eh: %d", resultado);
    return 0;
}
int multiplicacao(int n1, int n2){
    if(n2 == 1)
        return n1;
    return n1 + multiplicacao(n1, n2-1);
}