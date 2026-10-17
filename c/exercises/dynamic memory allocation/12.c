/*
Questão 12 -
Crie uma struct Aluno com:
- nome — vetor de caracteres com 50 posições.
- matricula — número inteiro.
- nota — número real (float).

Na main, leia a quantidade de alunos (N).
Aloque dinamicamente espaço para N estruturas Aluno usando malloc.
Verifique se a alocação foi bem-sucedida.
Utilize cadastrarAlunos() para preencher os dados.
Utilize exibirAlunos() para mostrar os dados.
Libere a memória com free() ao terminar.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[50];
    int matricula;
    float nota;
}Aluno;
void cadastrarAlunos(Aluno *alunos, int tam){
    for(int i = 0; i < tam; i++){
        printf("# Aluno %d:\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        printf("\n");
    }
}
void exibirAlunos(Aluno *alunos, int tam){
    for(int i = 0; i < tam; i++){
        printf("# Aluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nota: %.2f\n\n", alunos[i].nota);
    }
}
int main(void) {
    int N;

    printf("Quantidade de alunos: ");
    scanf("%d", &N);

    while(N <= 0){
        printf("Digite uma quantidade de alunos valida: ");
        scanf("%d", &N);
    }

    Aluno *alunos = calloc(N, sizeof(Aluno));

    if(alunos == NULL){
        printf("Erro ao alocar memoria!");
        return 1;
    }

    cadastrarAlunos(alunos, N);
    exibirAlunos(alunos, N);

    free(alunos);

    return 0;
}