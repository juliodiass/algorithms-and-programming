/*
6 - Faça um programa que leia os dados de 10 alunos (Nome, matrícula, Média Final),
armazenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores,
o vetor dos aprovados e o vetor dos reprovados, considerando a média mínima para a
aprovação como sendo 5.0.
Exibir na tela os dados do vetor de aprovados, seguido dos dados do vetor de reprovados.
*/
#include <stdio.h>
typedef struct{
    char nome[30];
    char matricula[10];
    float media_final;
}Aluno;
void qtd_alunos(Aluno alunos[10], Aluno aprovados[10], Aluno reprovados[10], int total,
                int *qtd_aprovados, int *qtd_reprovados){
    *qtd_aprovados = 0;
    *qtd_reprovados = 0;
    for(int i = 0; i < total; i++){
        if(alunos[i].media_final >= 5.0){
            aprovados[*qtd_aprovados] = alunos[i];
            (*qtd_aprovados)++;
        }
        else{
            reprovados[*qtd_reprovados] = alunos[i];
            (*qtd_reprovados)++;
        }
    }
}
int main(){
    Aluno alunos[10];
    Aluno aprovados[10];
    Aluno reprovados[10];
    int qtd_aprovados;
    int qtd_reprovados;
    for(int i = 0; i < 10; i++){
        printf("# Aluno %d\n", i+1);
        printf("Digite o nome: ");
        scanf(" %29[^\n]", alunos[i].nome);
        printf("Digite a matricula: ");
        scanf(" %9[^\n]", alunos[i].matricula);
        printf("Digite a media final do aluno: ");
        scanf("%f", &alunos[i].media_final);
        printf("\n");
    }
qtd_alunos(alunos, aprovados, reprovados, 10, &qtd_aprovados, &qtd_reprovados);
printf("# Alunos Aprovados:\n");
for(int i = 0; i < qtd_aprovados; i++){
    printf("Nome: %s\n", aprovados[i].nome);
    printf("Matricula: %s\n", aprovados[i].matricula);
    printf("Media final: %.2f\n", aprovados[i].media_final);
}
printf("# Alunos Reprovados:\n");
for(int i = 0; i < qtd_reprovados; i++){
    printf("Nome: %s\n", reprovados[i].nome);
    printf("Matricula: %s\n", reprovados[i].matricula);
    printf("Media final: %.2f\n", reprovados[i].media_final);
}
    return 0;
}
