/*
1) Escreva uma programa em linguagem C que declare, leia e mostre um vetor contendo 5 funcionários.
os funcionários devem ter: nome, data de nascimento, endereço completo e cpf.
*/
#include <stdio.h>
typedef struct{
    char nome[50];
    char dataNascimento[11];
    char endereco[100];
    char cpf[15];
}Funcionario;
void lerFuncionarios(Funcionario *funcionarios, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("# Funcionario %d\n", i+1);
        printf("Nome: ");
        scanf("%49[^\n]", funcionarios[i].nome);
        printf("Data de nascimento (XX/XX/XXXX): ");
        scanf("%10[^\n]", funcionarios[i].dataNascimento);
        printf("Endereco: ");
        scanf("%99[^\n]", funcionarios[i].endereco);
        printf("CPF (XXX.XXX.XXX-XX): ");
        scanf("%14[^\n]", funcionarios[i].cpf);
        printf("\n");
    }
}
void exibirFuncionarios(Funcionario *funcionarios, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("# Funcionario %d\n", i+1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Data de nascimento: %s\n", funcionarios[i].dataNascimento);
        printf("Endereco: %s\n", funcionarios[i].endereco);
        printf("CPF: %s\n", funcionarios[i].cpf);
        printf("\n");
    }
}
int main(){
    Funcionario funcionarios[5];
    lerFuncionarios(funcionarios, 5);
    exibirFuncionarios(funcionarios, 5);
    return 0;
}