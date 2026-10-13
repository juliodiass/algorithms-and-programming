/*
Questão 11 — Cadastro dinâmico de notas por aluno
Escreva um programa em C que permita cadastrar as notas de vários alunos usando alocação dinâmica de memória.
O programa deverá:
1. Perguntar quantos alunos serão cadastrados.
2. Alocar dinamicamente um vetor para armazenar as notas dos alunos.
3. Ler a nota de cada aluno, aceitando valores entre 0 e 100.
4. Caso o usuário digite uma nota inválida, solicitar novamente.
5. Permitir que o usuário aumente a quantidade de alunos cadastrados, utilizando realloc para expandir o vetor.
6. Ao finalizar, exibir todas as notas, a média da turma, a maior nota e a menor nota.
7. Liberar toda a memória alocada dinamicamente.
Requisitos técnicos:
- Utilize ponteiros e alocação dinâmica.
- Verifique se malloc e realloc falharam.
- Não perca o endereço original caso realloc falhe.
- Controle separadamente a quantidade de notas cadastradas e a capacidade atual do vetor.
- Valide as entradas do usuário.
*/

#include <stdio.h>
#include <stdlib.h>

float *cadastrarNotas(float *vet, int *quantidade, int *capacidade) {
    for (int i = 0; i < *quantidade; i++) {
        while (1) {
            printf("Digite a nota do aluno %d (0 a 100): ", i + 1);
            scanf("%f", &vet[i]);

            if (vet[i] >= 0 && vet[i] <= 100) {
                break;
            }

            printf("Nota invalida! Tente novamente.\n");
        }
    }

    char sn;
    printf("Deseja adicionar mais alunos? (S/N): ");
    scanf(" %c", &sn);

    if (sn == 'S' || sn == 's') {
        int adicionar;

        printf("Quantos alunos deseja adicionar? ");
        scanf("%d", &adicionar);

        if (adicionar <= 0) {
            printf("Quantidade invalida.\n");
            return vet;
        }

        int novaCapacidade = *capacidade + adicionar;

        float *temporario = realloc(
            vet, novaCapacidade * sizeof(float)
        );

        if (temporario == NULL) {
            printf("Nao foi possivel aumentar o vetor.\n");
            return vet;
        }

        vet = temporario;

        int inicio = *quantidade;
        *quantidade += adicionar;
        *capacidade = novaCapacidade;

        for (int i = inicio; i < *quantidade; i++) {
            while (1) {
                printf("Digite a nota do aluno %d (0 a 100): ", i + 1);
                scanf("%f", &vet[i]);

                if (vet[i] >= 0 && vet[i] <= 100) {
                    break;
                }

                printf("Nota invalida! Tente novamente.\n");
            }
        }
    }

    return vet;
}

int main() {
    int quantidade, capacidade;

    printf("Quantidade de alunos: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    capacidade = quantidade;

    float *vet = calloc(capacidade, sizeof(float));

    if (vet == NULL) {
        printf("Nao foi possivel alocar memoria.\n");
        return 1;
    }

    vet = cadastrarNotas(vet, &quantidade, &capacidade);

    float soma = 0;
    float maior = vet[0];
    float menor = vet[0];

    printf("\n--- Notas cadastradas ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("Aluno %d: %.2f\n", i + 1, vet[i]);

        soma += vet[i];

        if (vet[i] > maior) {
            maior = vet[i];
        }

        if (vet[i] < menor) {
            menor = vet[i];
        }
    }

    printf("\nMedia: %.2f\n", soma / quantidade);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);

    free(vet);

    return 0;
}