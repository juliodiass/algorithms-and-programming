/*
Questão 13-
Crie um programa em C que cadastre alunos usando um vetor alocado dinamicamente.
Requisitos:
1. Criar uma struct Aluno com nome[50] e nota.
2. Começar com espaço para 2 alunos, usando malloc.
3. Cadastrar os alunos por meio de uma função void.
4. Quando o vetor estiver cheio, perguntar se o usuário deseja cadastrar mais alunos.
5. Se quiser continuar, usar realloc para aumentar a capacidade em mais 2 posições.
6. Exibir todos os alunos cadastrados e calcular a média das notas.
7. Verificar falhas de alocação, preservar o ponteiro original se realloc falhar e liberar a memória com free.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

void cadastrarAlunos(Aluno *alunos, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n# Aluno %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
}

void exibirAlunos(Aluno *alunos, int quantidade) {
    float soma = 0;

    printf("\n--- Alunos cadastrados ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("\nNome: %s\n", alunos[i].nome);
        printf("Nota: %.2f\n", alunos[i].nota);

        soma += alunos[i].nota;
    }

    if (quantidade > 0) {
        printf("\nMedia das notas: %.2f\n", soma / quantidade);
    }
}

int main(void) {
    int quantidade = 0;
    int capacidade = 2;
    char sn;

    Aluno *alunos = malloc(capacidade * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    while (1) {
        // Cadastra somente o aluno que falta
        cadastrarAlunos(&alunos[quantidade], 1);
        quantidade++;

        if (quantidade == capacidade) {
            printf("\nVetor cheio! Deseja cadastrar mais alunos (S/N)? ");
            scanf(" %c", &sn);

            if (sn != 'S' && sn != 's') {
                break;
            }

            int novaCapacidade = capacidade + 2;

            Aluno *temporario = realloc(
                alunos, novaCapacidade * sizeof(Aluno)
            );

            if (temporario == NULL) {
                printf("Nao foi possivel aumentar o vetor.\n");
                break;
            }

            alunos = temporario;
            capacidade = novaCapacidade;
        }
    }

    exibirAlunos(alunos, quantidade);

    free(alunos);

    return 0;
}