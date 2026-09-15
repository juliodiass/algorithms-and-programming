/*
3 - . Considerando a estrutura
struct Vetor{
float x;
float y;
float z;
};
para representar um vetor no R3, implemente um programa que calcule
a soma de dois vetores.
*/
#include <stdio.h>
struct Vetor{
float x;
float y;
float z;
};
int main(){
    struct Vetor vetor_A;
    struct Vetor vetor_B;
    struct Vetor vetor_soma;

    printf("Digite os 3 valores do Vetor A: ");
    scanf("%f %f %f", &vetor_A.x, &vetor_A.y, &vetor_A.z);

    printf("Digite os 3 valores do Vetor B: ");
    scanf("%f %f %f", &vetor_B.x, &vetor_B.y, &vetor_B.z);

    vetor_soma.x = vetor_A.x + vetor_B.x;
    vetor_soma.y = vetor_A.y + vetor_B.y;
    vetor_soma.z = vetor_A.z + vetor_B.z;

    printf("\n");
    printf("A soma dos vetores e: %.1f, %.1f, %.1f", vetor_soma.x, vetor_soma.y, vetor_soma.z);

    return 0;
}
