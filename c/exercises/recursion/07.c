/*
Exercício 7 - Inverter um vetor recursivamente
*/
#include <stdio.h>
void ordenarVet(int *vet, int inicio, int fim);
int main(){
    int vet[6] = {10, 20, 30, 40, 50, 60};
    ordenarVet(vet, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", vet[i]);
    }
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