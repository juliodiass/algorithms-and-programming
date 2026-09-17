/*
5 - Utilizando uma estrutura, faça um programa que permita a entrada de nome,
endereço e telefone de 10 pessoas e os imprima em ordem alfabética.
PS: use a função strcmp(s1, s2) para comparar as duas strings.
*/
#include <stdio.h>
#include <string.h>
typedef struct{
    char nome[30];
    char endereco[30];
    char telefone[15];
}Dados;
void ordenar(Dados pessoas[10], int total){
    Dados aux;
    for(int i = 0; i < total; i++){
        for(int j = i+1; j < total; j++){
    if(strcmp(pessoas[i]. nome, pessoas[j].nome) > 0){
            aux = pessoas[i];
            pessoas[i] = pessoas[j];
            pessoas[j] = aux;
            }
        }
    }
}
int main(){
    Dados pessoas[10];
    for(int i = 0; i < 10; i++){
        printf("# Usuario %d\n", i+1);
        printf("Digite o nome: ");
        scanf(" %29[^\n]", pessoas[i].nome);
        printf("Digite o endereco: ");
        scanf(" %29[^\n]", pessoas[i].endereco);
        printf("Digite o telefone: ");
        scanf(" %14[^\n]", pessoas[i].telefone);
        printf("\n");
    }
ordenar(pessoas, 10);
printf("# Pessoas em ordem alfabetica:\n");
for(int i = 0; i < 10; i++){
    printf("# Pessoa %d\n", i+1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Endereco: %s\n", pessoas[i].endereco);
    printf("Telefone: %s\n", pessoas[i].telefone);
}
    return 0;
}
