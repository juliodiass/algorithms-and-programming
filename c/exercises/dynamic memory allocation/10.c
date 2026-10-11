/*
Questão 10-
Cadastro dinâmico de números
Escreva um programa em C que permita ao usuário inserir números inteiros em um vetor alocado dinamicamente.
O programa deverá:
1. Inicialmente, alocar dinamicamente espaço para 5 números inteiros.
2. Ler os números digitados pelo usuário, um de cada vez.
3. Quando o vetor estiver cheio, perguntar se o usuário deseja inserir mais números.
4. Se desejar continuar, utilizar realloc para aumentar a capacidade do vetor em mais 5 posições.
5. Ao final, exibir todos os números inseridos e a soma deles.
6. Liberar a memória alocada dinamicamente.
Requisitos:
- Utilize ponteiros e alocação dinâmica.
- Verifique se malloc e realloc falharam.
- Não perca o endereço original caso realloc falhe.
- Controle separadamente a quantidade de números inseridos e a capacidade atual do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int *adicionarNumeros(int *vet, int *quantidade, int *capacidade) {
    while (1) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &vet[*quantidade]);
        (*quantidade)++;

        if (*quantidade == *capacidade) {
            char sn;
            printf("Vetor cheio! Deseja adicionar mais numeros? (S/N): ");
            scanf(" %c", &sn);

            if (sn != 'S' && sn != 's') {
                break;
            }

            int novaCapacidade = *capacidade + 5;

            int *temporario = realloc(
                vet, novaCapacidade * sizeof(int)
            );

            if (temporario == NULL) {
                printf("Nao foi possivel aumentar o vetor.\n");
                break;
            }

            vet = temporario;
            *capacidade = novaCapacidade;
        }
    }

    return vet;
}

int main() {
    int quantidade = 0;
    int capacidade = 5;

    int *vet = malloc(capacidade * sizeof(int));

    if (vet == NULL) {
        printf("Nao foi possivel alocar memoria.\n");
        return 1;
    }

    vet = adicionarNumeros(vet, &quantidade, &capacidade);

    int soma = 0;

    printf("\nNumeros inseridos: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vet[i]);
        soma += vet[i];
    }

    printf("\nSoma: %d\n", soma);
    printf("Quantidade: %d\n", quantidade);
    printf("Capacidade: %d\n", capacidade);

    free(vet);
    return 0;
}
