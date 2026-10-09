/*
Questão 09-
Escreva uma função em C chamada cadastrarAlunos que receba como parâmetro um inteiro N, correspondente à quantidade de alunos que serão cadastrados.
Cada aluno deverá possuir uma estrutura com os seguintes dados:
- nome — string de até 50 caracteres;
- matricula — inteiro;
- nota — float.
A função deverá alocar dinamicamente um vetor com N alunos, ler os dados informados pelo usuário e retornar um ponteiro para esse vetor.
O cabeçalho da função deverá ser:
Aluno* cadastrarAlunos(int N);

Requisitos:
1. Defina a struct Aluno.
2. Utilize calloc ou malloc para alocar o vetor dinamicamente.
3. Leia os dados de cada aluno.
4. No main, receba o ponteiro retornado e exiba os dados cadastrados.
5. Libere a memória alocada com free().
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[50];
    int matricula;
    float nota;
}Aluno;

Aluno* cadastrarAlunos(int N){
    Aluno *alunos = (Aluno *) calloc(N, sizeof(Aluno));
    if (alunos == NULL) {
    return NULL;
    }   
    for(int i = 0; i < N; i++){
        printf("# Aluno %d\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        printf("\n");
    }
    return alunos;
}
int main(){
    int N;
    printf("Digite a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &N);
    while (N <= 0) {
        printf("Digite uma quantidade valida (maior que zero): ");
        scanf("%d", &N);
    }
    Aluno *alunos = cadastrarAlunos(N);
    if (alunos == NULL) {
    return 1;
    }
    for(int i = 0; i < N; i++){
        printf("# Aluno %d\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
    free(alunos);
    return 0;
}