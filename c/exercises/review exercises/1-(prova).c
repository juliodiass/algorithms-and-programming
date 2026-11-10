/*
a) Escreva uma função chamada calcular_salario_liquido que receba por parâmetro/ponteiro
a estrutura de um jogador (ou a lista de jogadores) e preencha o campo salario_liquido
aplicando o desconto sobre o salario_base: salario_liquido = salario base * (1 -
percentual_desconto/100);


b) Escreva uma função para receber o vetor de jogadores e realizar a leitura de todos os 5
jogadores;

c) Escreva uma função que recebe o vetor de jogadores e mostra todos os jogadores
cadastrados;

d) Escreva uma função que recebe o vetor de jogadores e mostre todos os dados de todos
os jogadores cadastrados em ordem alfabética;
*/
#include <stdio.h>
#include <string.h>
typedef struct{
    int dia;
    int mes;
    int ano;
}Data;
typedef struct{
    char nome[30];
    Data datanasc;
    float salariobase;
    float percentual_desconto;
    float salario_liquido;
}Jogador;
void preenchervetor(Jogador *jogadores, int N);
void calcular_salario_liquido(Jogador *jogadores, int N);
void mostrarjogadores(Jogador *jogadores, int N);
void mostrarordem(Jogador *jogadores, int N);
int main(){
    int N = 5;
    Jogador jogadores[N];

    preenchervetor(jogadores, N);
    calcular_salario_liquido(jogadores, N);
    mostrarjogadores(jogadores, N);
    mostrarordem(jogadores, N);

    return 0;
}

//a)
void calcular_salario_liquido(Jogador *jogadores, int N){
    for(int i = 0; i < N; i++){
        jogadores[i].salario_liquido = jogadores[i].salariobase * (1 - jogadores[i].percentual_desconto/100);
    }
}
//b)
void preenchervetor(Jogador *jogadores, int N){
    printf("---CADASTRAR JOGADORES--\n");
    for(int i = 0; i < N; i++){
        printf("Jogador %d:\n", i+1);
        printf("Nome: ");
        scanf(" %29[^\n]", jogadores[i].nome);
        printf("Data de nascimento: ");
        scanf("%d %d %d", &jogadores[i].datanasc.dia, &jogadores[i].datanasc.mes, &jogadores[i].datanasc.ano);
        printf("Salario base: ");
        scanf("%f", &jogadores[i].salariobase);
        printf("Percentual desconto: ");
        scanf("%f", &jogadores[i].percentual_desconto);
        printf("\n");
    }
}
//c)
void mostrarjogadores(Jogador *jogadores, int N){
    printf("\n---JOGADORES CADASTRADOS--\n");
    for(int i = 0; i < N; i++){
        printf("Jogador %d:\n", i+1);
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", jogadores[i].datanasc.dia, jogadores[i].datanasc.mes, jogadores[i].datanasc.ano);
        printf("Salario base: %.2f\n", jogadores[i].salariobase);
        printf("Percentual desconto: %.2f%%\n", jogadores[i].percentual_desconto);
        printf("Salario liquido: %.2f\n", jogadores[i].salario_liquido);
        printf("\n");
    }
}
//d
void mostrarordem(Jogador *jogadores, int N){
    Jogador aux;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(strcmp(jogadores[i].nome, jogadores[j].nome) > 0){
            aux = jogadores[i];
            jogadores[i] = jogadores[j];
            jogadores[j] = aux;
            }
        }
    }
    printf("\n---JOGADORES ORDENADOS--\n");
    for(int i = 0; i < N; i++){
        printf("Jogador %d:\n", i+1);
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", jogadores[i].datanasc.dia, jogadores[i].datanasc.mes, jogadores[i].datanasc.ano);
        printf("Salario base: R$%.2f\n", jogadores[i].salariobase);
        printf("Percentual desconto: %.2f%%\n", jogadores[i].percentual_desconto);
        printf("Salario liquido: R$%.2f\n", jogadores[i].salario_liquido);
        printf("\n");
    }
}