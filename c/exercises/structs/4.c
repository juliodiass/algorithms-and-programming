/*
4 - Faça um programa em C que armazene em uma estrutura de dados (estrutura composta)
os dados de um funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF,
Data de Nascimento, Codigo do Setor onde trabalha (0-99), Cargo que ocupa
(string de até 30 caracteres) e Salario.
Os dados devem ser digitados pelo usuario, armazenados na estrutura e exibidos na tela.
Considere que a empresa tem até 10 funcionários, sendo assim, para armazenar
todos os funcionários você deve definir um vetor do que armanzena a struct definida.
Implemente funções que recebe o vetor como argumento e:
a) retornar a quantidade de mulheres;
b) retorne e média de idade;
c) Retorne a quantidade de pessoas que recebem entre R$ 5000 e R$10000;
*/
#include <stdio.h>
struct Dados{
    char nome[30];
    int idade;
    char sexo;
    char CPF[15];
    char data_nasc[9];
    int setor;
    char cargo[30];
    float salario;
};
int qtd_mulheres(struct Dados funcionarios[10], int total){
    int qtd = 0;
    for(int i = 0; i < total; i++){
        if(funcionarios[i].sexo == 'F' || funcionarios[i].sexo == 'f'){
            qtd++;
        }
    }
    return qtd;
}
float calculo_media_idade(struct Dados funcionarios[10], int total){
    int soma = 0;
    float media = 0;
    for(int i = 0; i < total; i++){
        soma += funcionarios[i].idade;
        }
        media = (float)soma / total;
        return media;
}
int qtd_pessoas5k_10k(struct Dados funcionarios[10], int total){
    int qtd = 0;
    for(int i = 0; i < total; i++){
        if(funcionarios[i].salario >= 5000 && funcionarios[i].salario <= 10000){
            qtd++;
        }
    }
    return qtd;
}
void exibir_dados(struct Dados funcionarios[10], int total){
printf("########################\n");
printf("DADOS DOS FUNCIONARIOS:\n");
printf("########################\n");
for(int i = 0; i < total; i++){
    printf("Nome do funcionario %d: %s\n", i+1, funcionarios[i].nome);
    printf("Idade: %d\n", funcionarios[i].idade);
    printf("Sexo: %c\n", funcionarios[i].sexo);
    printf("CPF: %s\n", funcionarios[i].CPF);
    printf("Data de nascimento: %s\n", funcionarios[i].data_nasc);
    printf("Codigo do setor: %d\n", funcionarios[i].setor);
    printf("Cargo: %s\n", funcionarios[i].cargo);
    printf("Salario: %.2f\n", funcionarios[i].salario);
}
}
int main(){
    struct Dados funcionarios[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o nome do funcionario %d: ", i+1);
        scanf(" %29[^\n]", funcionarios[i].nome);

        printf("Digite a idade do funcioario: ");
        scanf("%d", &funcionarios[i].idade);

        printf("Digite o sexo do funcioario: ");
        scanf(" %c", &funcionarios[i].sexo);

        printf("Digite o CPF do funcionario no formato XXX.XXX.XXX-XX: ");
        scanf(" %14[^\n]", funcionarios[i].CPF);

        printf("Digite a data de nascimento do funcionario no formato XX/XX/XX: ");
        scanf(" %8[^\n]", funcionarios[i].data_nasc);

        printf("Digite o codigo do setor onde trabalha (0-99): ");
        scanf("%d", &funcionarios[i].setor);

        while(funcionarios[i].setor < 0 || funcionarios[i].setor > 99){
        printf("Digite um codigo valido (0-99): ");
        scanf("%d", &funcionarios[i].setor);
        }

        printf("Digite o cargo exercido: ");
        scanf(" %29[^\n]", funcionarios[i].cargo);

        printf("Digite o salario: ");
        scanf("%f", &funcionarios[i].salario);

        printf("\n");
    }
int total_mulheres = qtd_mulheres(funcionarios, 10);
float media_idade = calculo_media_idade(funcionarios,10);
int qtd_pessoas_salario = qtd_pessoas5k_10k(funcionarios, 10);

printf("O total de funcionarios que sao mulheres e: %d\n", total_mulheres);
printf("A media de idade dos funcionarios e: %.1f\n", media_idade);
printf("O total de pessoas que recebem entre 5-10k e de: %d", qtd_pessoas_salario);
printf("\n");
exibir_dados(funcionarios,10);
    return 0;
}
