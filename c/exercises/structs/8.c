/*
Questão 08 -
Crie uma struct Aluno com:
- nome — vetor de caracteres com 50 posições.
- matricula — número inteiro.
- nota — número real (float).

Na main, declare um vetor para armazenar os 5 alunos.
Crie uma função void cadastrarAlunos(...) que receba o vetor e a quantidade de alunos, lendo os dados de cada um.
Crie uma função void exibirAlunos(...) que receba o vetor e mostre os dados cadastrados.
Na main, chame as duas funções na ordem correta.
*/
#include <stdio.h>
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
int main(){
    Aluno alunos[5];
    cadastrarAlunos(alunos, 5);
    exibirAlunos(alunos, 5);
    return 0;
}