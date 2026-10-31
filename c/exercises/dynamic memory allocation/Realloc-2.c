#include <stdio.h>
#include <stdlib.h>

float *cadastroNotas(int qtd);
float *aumentarVetor(float *vet, int total);
float media(float *vet, int total);

int main() {
    int total = 2;
    int opcao;

    float *vet = cadastroNotas(total);

    if (vet == NULL) {
        return 1;
    }

    do {
        printf("\nDeseja adicionar mais uma nota? (1-SIM / 0-NAO): ");
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Opcao invalida! Digite 1 ou 0: ");
            scanf("%d", &opcao);
        }

        if (opcao == 1) {
            float *temp = aumentarVetor(vet, total);

            if (temp == NULL) {
                printf("Falha na realocacao!\n");
                break;
            }

            vet = temp;

            printf("Digite a nota do aluno %d: ", total + 1);
            scanf("%f", &vet[total]);

            total++;
        }

    } while (opcao == 1);

    printf("\n--- NOTAS CADASTRADAS ---\n");

    for (int i = 0; i < total; i++) {
        printf("Nota %d: %.2f\n", i + 1, vet[i]);
    }

    printf("\nMedia: %.2f\n", media(vet, total));

    free(vet);

    return 0;
}

float *cadastroNotas(int qtd) {
    float *vet = (float *) malloc(qtd * sizeof(float));

    if (vet == NULL) {
        printf("Falha na alocacao!\n");
        return NULL;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &vet[i]);
    }

    return vet;
}

float *aumentarVetor(float *vet, int total) {
    float *temp = (float *) realloc(vet, (total + 1) * sizeof(float));

    if (temp == NULL) {
        return NULL;
    }

    return temp;
}

float media(float *vet, int total) {
    float soma = 0;

    for (int i = 0; i < total; i++) {
        soma += vet[i];
    }

    return soma / total;
}