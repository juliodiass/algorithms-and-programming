/*
4) Considere o tipo struct vendedor, definido abaixo, e:
(b) Escreva outra função que receba o vetor criado no item (a), 
percorra o vetor e retorne outro vetor contendo somente os vendedores 
com idade acima de 40 anos.
struct vendedor{
  char nome[20];
  int idade;
  float salario;
};
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char nome[20];
  int idade;
  float salario;
}vendedor;
// Cadastrar vendedores
vendedor *cadastrarVendedores(int N){
    vendedor *vet = (vendedor *) calloc(N, sizeof(vendedor)); //Alocação dinâmica do vetor
    if(vet == NULL){ //Validação da alocação
        printf("Nao foi possivel alocar memoria!\n");
        return NULL;
    }
    printf("*** CADASTRO DE VENDEDORES ***\n");
    for(int i = 0; i < N; i++){
        printf("# Vendedor %d\n", i+1);
        printf("Digite o nome do vendedor: ");
        scanf(" %19[^\n]", vet[i].nome);
        printf("Digite a idade do vendedor: ");
        scanf("%d", &vet[i].idade);
        printf("Digite o salario do vendedor: ");
        scanf("%f", &vet[i].salario);
        printf("\n");
    }
    return vet; //Retorna o vetor com os vendedores já cadastrados
}
vendedor *vendedores40(vendedor *vet, int N, int *novotam){
    vendedor *vet40 = NULL; // O novo vetor dos 40+ é inicializado com 0 espaços
    *novotam = 0;
    for(int i = 0; i < N; i++){
        if(vet[i].idade > 40){
            vendedor *temp = (vendedor*) realloc(vet40, (*novotam+1) * sizeof(vendedor)); //O vetor é reallocado de acordo com a quantidade de vendedores 40+
            if(temp == NULL){
                printf("Nao foi possivel realocar memoria!\n");
                free(vet40);
                return NULL;
            }
            vet40 = temp; //O vetor temporário passa o tamanho ao vetor original
            vet40[*novotam] = vet[i]; //O vetor com as informações do vendedor é passado ao vetor dos 40+
            (*novotam)++; //O tamanho do novo vetor é atualizado
        }
    }
    return vet40;
}
int main(){
    int N;
    int novotam;
    printf("Digite a quantidade de vendedores a serem cadastrados: ");
    scanf("%d", &N);
    while(N <= 0){ //Validação da quantidade de vendedores a serem cadastrados
        printf("Digite uma quantidade valida: ");
        scanf("%d", &N);
    }

    vendedor *vet = cadastrarVendedores(N); //É declarado um novo vetor no qual irá receber como retorno da função o vetor com os vendedores cadastrados
    if (vet == NULL) {
    return 1;
    }
    //Exibe as informações dos vendedores cadastrados
    printf("### VENDEDORES ###\n");
    for(int i = 0; i < N; i++){
        printf("# Vendedor %d\n", i+1);
        printf("Nome: %s\n", vet[i].nome);
        printf("Idade: %d\n", vet[i].idade);
        printf("Salario: %.2f\n", vet[i].salario);
        printf("\n");
    }
    
    vendedor *vet40 = vendedores40(vet, N, &novotam); //É declarado um novo vetor no qual irá receber como retorno da função o vetor com os vendedores 40+
    if (vet40 == NULL){
        free(vet);
    return 1;
    }
    if(novotam == 0){
        printf("Nao existem vendedores com idade superior a 40 anos!\n");
    }
    //Exibe os vendedores com idade superior a 40
    printf("**** Vendedores com idade acima de 40 anos ****\n");
    for(int i = 0; i < novotam; i++){
        printf("Nome: %s\n", vet40[i].nome);
        printf("Idade: %d\n", vet40[i].idade);
        printf("Salario: %.2f\n", vet40[i].salario);
        printf("\n");
    }

    free(vet);
    free(vet40);
    return 0;
}