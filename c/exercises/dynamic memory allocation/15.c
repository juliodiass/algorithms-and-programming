/*
Questão 15 - Notas dos alunos
Escreva um programa em C que:
1. Pergunte ao usuário quantas notas ele deseja armazenar.
2. Aloque dinamicamente a memória usando calloc.
3. Verifique se a alocação funcionou.
4. Leia todas as notas digitadas.
5. Mostre as notas armazenadas.
6. Libere a memória utilizando free.
Regras:
- Utilize int *notas para declarar o ponteiro.
- Utilize o type casting, como você aprendeu na faculdade.
- Use um for para ler e outro para mostrar as notas.
- Não utilize um vetor de tamanho fixo.
*/
#include <stdio.h>
#include <stdlib.h>
void lerNotas(int *notas, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("# Nota %d: ", i+1);
        scanf("%d", &notas[i]);
    }
    printf("\n");
}
int main(){
    int qtd;
    printf("Digite a quantidade de notas serao armazenadas: ");
    scanf("%d", &qtd);
    while(qtd <= 0){
        printf("Digite uma quantidade valida!: ");
        scanf("%d", &qtd);
    }

    int *notas = (int *) calloc(qtd, sizeof(int));
    if(notas == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        return 1;
    }

    lerNotas(notas, qtd);
    printf("### NOTAS ###\n");
    for(int i = 0; i < qtd; i++){
        printf("# Nota %d: %d\n", i+1, notas[i]);
    }
    free(notas);
    return 0;
}