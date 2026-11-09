/*
Crie um programa em C que:
1. Pergunte ao usuário quantos números deseja armazenar.
2. Aloque o vetor utilizando calloc().
3. Receba os números e armazene no vetor.
4. Pergunte quantas posições o usuário deseja adicionar ao vetor.
5. Utilize realloc() para aumentar o vetor.
6. Solicite somente os novos números.
7. Exiba todos os elementos do vetor atualizado.
8. Libere a memória utilizando free().
*/
#include <stdio.h>
#include <stdlib.h>
int *alocarvetor(int qtd);
int *realocalocarvetor(int *vet, int newqtd, int qtd);
int main(){
    int qtd;
    printf("Quantos numeros deseja armazenar: ");
    scanf("%d", &qtd);
    int *vet = alocarvetor(qtd);
    int newqtd;
    printf("Quantos numeros deseja adicionar ao vetor: ");
    scanf("%d", &newqtd);
    vet = realocalocarvetor(vet, newqtd, qtd);
    newqtd += qtd;
    for(int i = 0; i < newqtd; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
int *alocarvetor(int qtd){
    int *vet = (int *) calloc(qtd, sizeof(int));
    if(vet == NULL){
        return NULL;
    }
    printf("Digite os %d numeros: ", qtd);
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    return vet;
}
int *realocalocarvetor(int *vet, int newqtd, int qtd){
    newqtd += qtd;
    int *temp = (int *) realloc(vet, newqtd * sizeof(int));
    if(temp == NULL){
        return NULL;
    }
    vet = temp;
    printf("Digite os %d novos numeros: ", newqtd - qtd);
    for(int i = qtd; i < newqtd; i++){
        scanf("%d", &vet[i]);
    }
    return vet;
}
