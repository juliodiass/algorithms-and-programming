/*
Requisitos
1. Struct Aluno
- nome: char[50]
- matricula: int
- nota1: float
- nota2: float
- media: float
2. Na main()
- Perguntar quantos alunos serão cadastrados.
- Alocar dinamicamente o vetor utilizando calloc.
- Fazer a validação da alocação.
- Chamar as funções necessárias.
3. Criar as funções
Função	                  Responsabilidade
cadastrarAlunos()	      Receber o vetor e preencher os dados
calcularMedias()	      Calcular a média de cada aluno
mostrarAlunos()	          Exibir os dados cadastrados
encontrarMelhorAluno()	  Retornar o aluno com maior média

4. Regras
- Utilize passagem de struct por ponteiro.
- Utilize funções com retorno quando fizer sentido.
- Utilize calloc com type cast.
- Valide as notas (0 a 10).
- Libere a memória com free().
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float media;
}Aluno;
Aluno *cadastrarAlunos(int qtd);
float calcularMedias(Aluno *alunos);
void mostrarAlunos(Aluno *alunos, int qtd);
int encontrarMelhorAluno(Aluno *alunos, int qtd);
int main(){
    int qtd;
    printf("---CADASTRO DE ALUNOS---\n");
    printf("Quantos alunos serao cadastrados: ");
    scanf("%d", &qtd);
    Aluno *alunos = cadastrarAlunos(qtd);
    if(alunos == NULL){
        printf("A alocacao falhou!\n");
        return 1;
    }
    mostrarAlunos(alunos, qtd);
    int maior = encontrarMelhorAluno(alunos, qtd);
    printf("O aluno %d: %s tem a maior media!", maior+1, alunos[maior].nome);

    free(alunos);
    return 0;
}
Aluno *cadastrarAlunos(int qtd){
    Aluno *alunos = (Aluno *) calloc(qtd, sizeof(Aluno));
    if(alunos == NULL){
        printf("A alocacao falhou!\n");
        return NULL;
    }
    for(int i = 0; i < qtd; i++){
        printf("# ALUNO %d\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        do{
            printf("Nota 1: ");
            scanf("%f", &alunos[i].nota1);
        }while(alunos[i].nota1 < 0 || alunos[i].nota1 > 10);
        do{
            printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        }while(alunos[i].nota2 < 0 || alunos[i].nota2 > 10);
        alunos[i].media = calcularMedias(&alunos[i]);
        printf("\n");
    }
    return alunos;
}
float calcularMedias(Aluno *alunos){
    float soma = alunos->nota1 + alunos->nota2;
    float media = soma / 2;
    return media;
}
void mostrarAlunos(Aluno *alunos, int qtd){
    printf("---ALUNOS CADASTRADOS---\n");
    for(int i = 0; i < qtd; i++){
        printf("# ALUNO %d\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota2: %.2f\n", alunos[i].nota2);
        printf("Media: %.2f\n", alunos[i].media);
        printf("\n");
    }
}
int encontrarMelhorAluno(Aluno *alunos, int qtd){
    int maior = 0;
    for(int i = 0; i < qtd; i++){
        if(alunos[i].media > alunos[maior].media){
            maior = i;
        }
    }
    return maior;
}