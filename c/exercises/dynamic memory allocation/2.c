/*
Questao 2:
2 - José Cardoso, é diretor da escola Estadual Maria Santos, ele precisa de um software que manipule as notas dos alunos de uma turma. 
Porém, ele não sabe ao certo quantos alunos tem em cada turma. E em geral esse valor não fixo devido a reprovação em matemática e desistências. 
Logo, José Cardoso precisa armazenar as notas em "vetor Dinâmico", faça um programa em C que permita: José inserir n notas (ele deve informar quantas 
notas quer inserir), ao final o programa deve mostrar a maior nota, a média das notas e ainda uma informação de aprovado ou reprovado com base na nota do aluno. 
(notas acima de 59.99 estão aprovados).
*/
#include <stdio.h>
#include <stdlib.h>
int calculo_maior(int *vet, int qtd_alunos){
    int aux = 0;
    for(int i = 0; i < qtd_alunos; i++){
        if(vet[i] > aux){
            aux = vet[i];
        }
    }
    return aux;
}
float calculo_media(int *vet, int qtd_alunos){
    float aux = 0;
    int soma = 0;
    for(int i = 0; i < qtd_alunos; i++){
        soma += vet[i];
    }
    aux = (float)soma / qtd_alunos;
    return aux;
}
void informacao(int *vet, int qtd_alunos){
    for(int i = 0; i < qtd_alunos; i++){
        if(vet[i] >= 60){
            printf("O aluno %d foi aprovado!\n", i+1);
        }
        else{
            printf("O aluno %d foi reprovado!\n", i+1);
        }
    }
}
int main(){
    int *vet, qtd_alunos;
    int maior = 0;
    float media = 0;
    printf("Digite a quantidade de notas a serem inseridas: ");
    scanf("%d", &qtd_alunos);

    vet = malloc(qtd_alunos * sizeof(int));
    if(vet == NULL){
        printf("Erro ao alocar memoria!\n");
        return 0;
    }

    printf("Digite as notas dos %d alunos: ", qtd_alunos);
    for(int i = 0; i < qtd_alunos; i++){
        scanf("%d", &vet[i]);
    }
    maior = calculo_maior(vet, qtd_alunos);
    media = calculo_media(vet, qtd_alunos);
    informacao(vet, qtd_alunos);

    printf("Maior nota: %d\n", maior);
    printf("Media notas: %.2f\n", media);

    free(vet);
    return 0;
}