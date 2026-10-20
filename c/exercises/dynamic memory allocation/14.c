/*
Questão 14-
Faça um programa em C que:
1. Pergunte quantos números inteiros o usuário deseja armazenar inicialmente.
2. Aloque a memória usando malloc com type casting, como seu professor ensinou.
3. Leia e armazene os números.
4. Pergunte se o usuário deseja adicionar mais números.
5. Se sim, use realloc para aumentar o vetor.
6. Mostre todos os números e libere a memória com free.
*/
#include <stdio.h>
#include <stdlib.h>
int *armazenarNum(int *vet, int *qtd) {
    printf("Digite os %d numeros: ", *qtd);

    for (int i = 0; i < *qtd; i++) {
        scanf("%d", &vet[i]);
    }

    char sn;
    int novotam;

    printf("Deseja adicionar mais numeros? (S/N): ");
    scanf(" %c", &sn);

    if (sn == 'S' || sn == 's') {
        printf("Quantos numeros serao adicionados: ");
        scanf("%d", &novotam);

        if (novotam <= 0) {
            printf("Quantidade invalida!\n");
            return vet;
        }

        int quantidadeAntiga = *qtd;
        int novacapacidade = quantidadeAntiga + novotam;

        int *temporario = (int *) realloc(
            vet, novacapacidade * sizeof(int)
        );

        if (temporario == NULL) {
            printf("Falha ao realocar memoria!\n");
            return vet;
        }

        vet = temporario;
        *qtd = novacapacidade;

        printf("Digite os novos %d numeros: ", novotam);

        for (int i = quantidadeAntiga; i < *qtd; i++) {
            scanf("%d", &vet[i]);
        }
    }
    return vet;
}

int main() {
    int qtd;

    printf("Digite quantos numeros inteiros serao armazenados: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    int *vet = (int *) malloc(qtd * sizeof(int));

    if (vet == NULL) {
        printf("Falha ao alocar memoria!\n");
        return 1;
    }

    vet = armazenarNum(vet, &qtd);

    printf("\nNumeros armazenados: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    free(vet);
    
    return 0;
}