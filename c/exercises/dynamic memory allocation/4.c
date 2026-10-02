/*
 
4 - Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades de elementos, n1 e n2. 
A função deverá retornar um ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente, contendo a união de v1 e v2. 
Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}.

O cabeçalho dessa função deverá ser o seguinte:
int* uniao(int *v1, int n1, int *v2, int n2);

Em seguida, crie a função principal do programa para chamar a função uniao passando dois vetores informados pelo usuário (declarados estaticamente). 
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
int* uniao(int *v1, int n1, int *v2, int n2){
    int n3 = n1 + n2;

    int *v3 = malloc(n3 * sizeof(int));

    if(v3 == NULL){
        return NULL;
    }

    for(int i = 0; i < n1; i++){
        v3[i] = v1[i];
    }

    for(int i = 0; i < n2; i++){
        v3[i + n1] = v2[i];
    }

    return v3;
}
int main(){
    int n1, n2, n3, *v3;
    printf("Digite o tamanho dos vetores n1 e n2: ");
    scanf("%d %d", &n1, &n2);
    n3 = n1 + n2;
    int v1[n1], v2[n2];
    lervetor(v1, n1, v2, n2);

    v3 = uniao(v1, n1, v2, n2);
    if(v3 == NULL){
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    printf("V3: ");
    for(int i = 0; i < n3; i++){
        printf("%d ", v3[i]);
    }
    free(v3);
    return 0;
}