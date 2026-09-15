/*
2 - Construa uma estrutura Aluno (Em C) com nome, numero de matricula e
curso. Leia do usuário a informação de 5 alunos, armazene em um vetor dessa
estrutura e imprima os dados na tela.
*/
#include <stdio.h>
struct Aluno{
    char nome[30];
    int num_matricula;
    char curso[20];
};
int main(){
    struct Aluno alunos[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o nome do aluno %d: ", i+1);
        scanf(" %29[^\n]", alunos[i].nome);

        printf("Digite o numero de matricula do aluno %d: ", i+1);
        scanf("%d", &alunos[i].num_matricula);

        printf("Digite o nome do curso do aluno %d: ", i+1);
        scanf(" %19[^\n]", alunos[i].curso);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("Aluno %d: %s\n", i+1, alunos[i].nome);
        printf("Numero de matricula: %d\n", alunos[i].num_matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("\n");
    }
    return 0;
}
