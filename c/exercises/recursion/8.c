/*
Exercicio 8 - Verificar se um vetor está em ordem crescente
*/
#include <stdio.h>
void ordenarVet(int *vet, int inicio, int fim);
int verificarVet(int *vet, int inicio, int fim);
int main(){
    int vet[6] = {10, 20, 30, 40, 50, 60};
    ordenarVet(vet, 0, 5);
    int resultado = verificarVet(vet, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", vet[i]);
    }
    printf("\nEsta ordenado = 1 ou nao = 0: %d", resultado);
    return 0;
}
void ordenarVet(int *vet, int inicio, int fim){
    int aux;
    if(inicio >= fim)
        return;
    aux = vet[inicio];
    vet[inicio] = vet[fim];
    vet[fim] = aux;
    inicio++;
    fim--;
    return ordenarVet(vet, inicio, fim);
}
int verificarVet(int *vet, int inicio, int fim){
    if(inicio >= fim)
        return 1;

    if(vet[inicio] >= vet[inicio+1])
        return 0;
    return verificarVet(vet, inicio + 1, fim);
}