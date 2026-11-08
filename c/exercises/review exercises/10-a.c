/*
a) Escreva uma função em C que recebe como argumentos um vetor (int *vet) de inteiros e
seu tamanho e retorna outro vetor contendo somente os números primos que estão em vet.
Obs.: você pode passar outros parâmetros para a função.
Protótipo:
int * alocaPrimos(int *vet, int tamanho);

Use a função abaixo como auxiliar.
int verificarPrimo(int n){
for(int i = 2 ;i < n/2; i++){
if (n % i == 0)
return 0;
}
return 1;
}
*/
#include <stdio.h>
#include <stdlib.h>
int *alocaPrimos(int *vet, int tamanho, int *qtd);
int verificarPrimo(int n);
int main(){
    int vet[] = {1, 2, 6, 11, 5};
    int qtd = 0;
    int *vetprimos = alocaPrimos(vet, 5, &qtd);
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