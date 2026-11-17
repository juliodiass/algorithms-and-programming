/*
Exercício 5 — Soma dos elementos de um vetor
Crie uma função recursiva que receba um vetor de inteiros e seu tamanho e retorne a soma de todos os seus elementos.
*/
#include <stdio.h>
int calcularsoma(int *vet, int qtd);
int main(){
    int vet[5] = {2, 4, 6, 8, 10};
    int resultado = calcularsoma(vet, 0);
    printf("O resultado da soma do vetor e: %d", resultado);
    return 0;
}
int calcularsoma(int *vet, int qtd){
    int resultado = 0;
    if(qtd == 5){
        return 0;
    }
    resultado += vet[qtd];
    return resultado + calcularsoma(vet, qtd + 1);
}