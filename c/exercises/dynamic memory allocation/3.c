/*
3 - Cria uma função chamada lerMedicos que, dada uma estrutura de dados do tipo médico com: nome, crm (14 digitos) e renda, leia n médicos, 
coloque em um vetor e retorne esse vetor. o valor n será passado pelo usuário da função como parametros da funçao.
*/
#include <stdio.h>
#include <string.h>
typedef struct{
    char nome[30];
    char CRM[15];
    float renda;
}Info;
Info *lerMedicos(Info *medicos, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o nome do medico %d: ", i + 1);
        scanf(" %29[^\n]", medicos[i].nome);
        printf("Digite o CRM: ");
        scanf(" %14[^\n]", medicos[i].CRM);
        printf("Digite a renda: ");
        scanf("%f", &medicos[i].renda);
    }
    return medicos;
}
int main(){
    int n;
    printf("Digite a quantidade de medicos que serao analisados: ");
    scanf("%d", &n);
    Info medicos[n];
    lerMedicos(medicos, n);
    
    for(int i = 0; i < n; i++){
        printf("Informações do médico %d: ", i + 1);
        printf("%s\n", medicos[i].nome);
        printf("%s\n", medicos[i].CRM);
        printf("%.2f\n", medicos[i].renda);
        printf("\n");
    }
    return 0;
}