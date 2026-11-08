/*
b) Crie outra função chamada 'fuzao()' que vai receber como argumentos o vetor retornado
pela função alocaPrimos() e seu tamanho. A função fuzao() deve então, concatenar o vetor
recebido como argumento com o vetor [3, 13, 7, 23, 37, 11] e retornar o novo vetor.
O protótipo da função:
int * fuzao(int *primos, int tamanho);
*/
#include <stdio.h>
#include <stdlib.h>
int *alocaPrimos(int *vet, int tamanho, int *qtd);
int verificarPrimo(int n);
int *fuzao(int *vetprimos, int *qtd);
int main(){
    int vet[] = {1, 2, 6, 11, 5};
    int qtd = 0;
    int *vetprimos = alocaPrimos(vet, 5, &qtd);
    printf("--PRIMOS--\n");
    for(int i = 0; i < qtd; i++){
        printf("%d ", vetprimos[i]);
    }
    vetprimos = fuzao(vetprimos, &qtd);
    printf("\n--CONCATENADOS--\n");
    for(int i = 0; i < qtd; i++){
        printf("%d ", vetprimos[i]);
    }
    free(vetprimos);
    return 0;
}
int *alocaPrimos(int *vet, int tamanho, int *qtd){
    int *vetprimos = (int *) malloc(tamanho * sizeof(int));
    int verifica;
    *qtd = 0;
    for(int i = 0; i < tamanho; i++){
        verifica = verificarPrimo(vet[i]);
        if(verifica == 1){
            vetprimos[*qtd] = vet[i];
            (*qtd)++;
        }
    }
    return vetprimos;
}
int verificarPrimo(int n){
    if(n < 2)
        return 0;
for(int i = 2; i * i <= n; i++){
    if (n % i == 0)
        return 0;
    }
    return 1;
}
int *fuzao(int *vetprimos, int *qtd){
    int newqtd = *qtd + 6;
    vetprimos = (int *) realloc(vetprimos, newqtd * sizeof(int));
    int vetor[6] = {3, 13, 7, 23, 37, 11};
    for(int i = 0; i < 6; i++){
        vetprimos[*qtd + i] = vetor[i];
    }
    *qtd += 6;
    return vetprimos;
}