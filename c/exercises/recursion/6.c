/*
Exercício 6
Crie uma função recursiva que encontre e retorne o maior elemento de um vetor.
*/
#include <stdio.h>
int maiorElemento(int *vet, int qtd);
int main(){
    int vet[6] = {12, 5, 28, 3, 19, 7};
    int resultado = maiorElemento(vet, 0);
    printf("O maior elemento e: %d", resultado);
    return 0;
}
int maiorElemento(int *vet, int qtd){
    if(qtd == 5)
        return vet[qtd];

    int proximo = maiorElemento(vet, qtd+1);

    if(vet[qtd] < proximo)
        return proximo;
    else
        return vet[qtd];
}