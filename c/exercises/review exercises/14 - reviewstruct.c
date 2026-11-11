/*
Exercício — Cadastro de alunos
Objetivo: criar um programa que cadastre alunos, armazene suas notas e calcule suas médias.
Requisitos
1. Criar uma struct Aluno contendo:
   - nome (string de até 50 caracteres).
   - idade (inteiro).
   - nota1 (float).
   - nota2 (float).
2. Na main(), declarar um vetor capaz de armazenar 3 alunos.
3. Criar uma função cadastrarAlunos() que receba o vetor e preencha os dados.
4. Criar uma função calcularMedia() que receba um aluno e retorne sua média.
5. Criar uma função mostrarAlunos() que exiba os dados.
*/
#include <stdio.h>
typedef struct{
    char nome[50];
    int idade;
    float nota1;
    float nota2;
}Aluno;
void cadastrarAlunos(Aluno *alunos, int qtd){
    printf("---Cadastro de Alunos---\n");
    for(int i = 0; i < qtd; i++){
        printf("Aluno %d:\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("\n");
    }
}
float calcularMedia(Aluno aluno){
    float soma = aluno.nota1 + aluno.nota2;
    float media = soma / 2;
    return media;
}
void mostrarAlunos(Aluno *alunos, int qtd){
    printf("---Resultados---\n");
    for(int i = 0; i < qtd; i++){
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        float media = calcularMedia(alunos[i]);
        printf("Media: %.2f\n", media);
        if(media >= 7){
            printf("Aprovado!\n");
        }
        else{
            printf("Reprovado!\n");
        }
    }
}
int main(){
    Aluno alunos[3];
    cadastrarAlunos(alunos, 3);
    mostrarAlunos(alunos, 3);
    return 0;
}