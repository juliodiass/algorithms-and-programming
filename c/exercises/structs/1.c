/*
1 - Implemente um programa em C que leia o nome, a idade e o endereço de
uma pessoa e armazene os dados em uma estrutura. Mostre a estrutura.
*/
#include <stdio.h>
struct Pessoa{
    char nome[30];
    int idade;
    char endereco[30];
    };
int main(){
    struct Pessoa dados;
    printf("Digite um nome: ");
    scanf("%29[^\n]", dados.nome);

    printf("Digite a idade: ");
    scanf("%d", &dados.idade);

    printf("Digite um endereco: ");
    scanf(" %29[^\n]", dados.endereco);

    printf("\n");
    printf("Nome: %s\n", dados.nome);
    printf("Idade: %d anos\n", dados.idade);
    printf("Endereco: %s", dados.endereco);

    return 0;
}


