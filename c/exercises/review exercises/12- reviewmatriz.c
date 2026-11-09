/*
Crie um programa em C que permita ao usuário escolher as dimensões de uma matriz e armazenar números inteiros.

Requisitos:
1. Solicite a quantidade de linhas e colunas.
2. Aloque a matriz utilizando calloc().
3. Crie uma função para preencher a matriz.
4. Crie uma função para exibir a matriz.
5. Crie uma função para liberar toda a memória.
6. Trate possíveis falhas de alocação.
*/
#include <stdio.h>
#include <stdlib.h>
int **alocarmatriz(int linhas, int colunas);
void preenchermatriz(int **matriz, int linhas, int colunas);
void exibirmatriz(int **matriz, int linhas, int colunas);
int main(){
    int linhas, colunas;
    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);
    int **matriz = alocarmatriz(linhas, colunas);
    preenchermatriz(matriz, linhas, colunas);
    exibirmatriz(matriz, linhas, colunas);
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
int **alocarmatriz(int linhas, int colunas){
    int **matriz = (int **) calloc(linhas, sizeof(int *));
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) calloc(colunas, sizeof(int));
    }
    return matriz;
}
void preenchermatriz(int **matriz, int linhas, int colunas){
    printf("Digite os valores para preencher o vetor: ");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}
void exibirmatriz(int **matriz, int linhas, int colunas){
    printf("Valores armazenados: \n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}
