#include <stdio.h>
#include <stdlib.h>
int main(){
    int linhas, colunas;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    int **matriz = (int **) calloc(linhas, sizeof(int *));
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) calloc(colunas, sizeof(int));
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Digite o elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);

        }
    }
    for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
    }
    free(matriz);
    return 0;
}