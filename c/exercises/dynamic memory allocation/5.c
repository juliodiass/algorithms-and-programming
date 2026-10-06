/*
Questão 05:
Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades de elementos, n1 e n2. 
A função deverá retornar um ponteiro para um terceiro vetor, v3, alocado dinamicamente, contendo a interseção de v1 e v2. 
Por exemplo, se v1 = {11, 10, 45, 7, 4} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {10, 4}.

O cabeçalho dessa função deverá ser o seguinte:
int* intersecao(int *v1, int n1, int *v2, int n2);

Em seguida, crie a função principal do programa para chamar a função intersecao passando dois vetores informados pelo usuário (declarados estaticamente). 
Em seguida, o programa deve exibir na tela os elementos do vetor resultante. Não esqueça de liberar a memória alocada dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>
void lervetor(int *v1, int n1, int *v2, int n2){
    printf("Escreva os elementos de V1: ");
    for(int i = 0; i < n1; i++){
        scanf("%d", &v1[i]);
    }
    printf("Escreva os elementos de V2: ");
    for(int i = 0; i < n2; i++){
        scanf("%d", &v2[i]);
    }
}
int *intersecao (int *v1, int n1, int *v2, int n2, int *qtd){
    *qtd = 0;
    int tamanho = n1;
    if(tamanho > n2)
        tamanho = n2;
    int *v3 = malloc(tamanho * sizeof(int));
        for(int i = 0; i < n1; i++){
            int iguais = 0;
            for(int j = 0; j < n2; j++){
                if(v1[i] == v2[j]){
                    for(int k = 0; k < *qtd; k++){
                        if(v3[k] == v1[i]){
                            iguais = 1;
                        }
                }
            if(iguais == 0){
                    v3[*qtd] = v1[i];
                    (*qtd)++;
                    }
            }
        }
    }
    if(*qtd == 0){
        free(v3);
        printf("Nao ha interseccao!\n");
        return NULL;
    }
    v3 = realloc(v3, *qtd * sizeof(int));
    return v3;
}
int main(){
    int n1, n2, *v3, qtd;
    printf("Digite o tamanho dos vetores n1 e n2: ");
    scanf("%d %d", &n1, &n2);
    int v1[n1], v2[n2];
    lervetor(v1, n1, v2, n2);

    v3 = intersecao (v1, n1, v2, n2, &qtd);
    printf("A interseccao entre o V1 e V2 e: ");
    for(int i = 0; i < qtd; i++){
        printf("%d ", v3[i]);
    }
    free(v3);
    return 0;
}