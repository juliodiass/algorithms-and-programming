/*
3) Escreva uma função em C que receba como argumento um número inteiro X e um número inteiro N. A função deve gerar os elementos da série:
X + 1/1, X + 1/2, X + 1/3, X + 1/4,   ...      , X + 1/(N-1),  X + 1/N.
Colocar em um vetor dinâmico e, por fim, a função deve retornar o vetor gerado.
Lembre-se que para que seja possível uma função retornar um vetor de forma segura em linguagem C esse vetor deve ser dinâmico.  
Protótipo da função
float * questao3(int X, int N);

Exemplo:  na chamada vet = questao3(2, 6);  o vetor vet seria composto por:
vet = [2+1/1, 2+1/2, 2+1/3, 2+1/4, 2+1/5, 2+1/6]
*/
#include <stdio.h>
#include <stdlib.h>
float *questao3(int X, int N){
    float *vet = (float *) calloc(N, sizeof(float));
    if(vet == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        return NULL;
    }

    for(int i = 0; i < N; i++){
        vet[i] = X + 1.0f/(i + 1);
    }
    return vet;
}
int main(){
    int X, N;
    printf("Digite a quantidade de elementos da serie: ");
    scanf("%d", &N);
    while(N <= 0){
        printf("Digite uma quantidade valida!: ");
        scanf("%d", &N);
    }
    printf("Digite qual sera o numero da serie: ");
    scanf("%d", &X);

    

    float *vet = questao3(X, N);
    if (vet == NULL) {
        return 1;
    }
    
    for(int i = 0; i < N; i++){
        printf("%.2f, ", vet[i]);
    }

    free(vet);
    return 0;
}