/*
7 - Faça um programa que gerencie o estoque de um mercado e:
Crie e leia um vetor de 5 produtos, com os dados: código (inteiro), nome (máximo 15 letras),
preço e quantidade.
Leia um pedido, composto por um código de produto e a quantidade.
Localize este código no vetor e, se houver quantidade suficiente para
atender ao pedido integralmente, atualize o estoque e informe o usuário.
Repita este processo até ler um código igual a zero.
Se, por algum motivo, não for possível atender ao pedido, mostre uma mensagem informando
qual erro ocorreu.
*/
#include <stdio.h>
typedef struct{
    int codigo;
    char nome[15];
    float preco;
    int quantidade;
}Produto;
void cabecalho(){
printf("********************\n");
printf("SUPERMERCADO EXPRESS\n");
printf("********************\n\n");
}
void ler_produtos(Produto produtos[5], int total){
    for(int i = 0; i < total; i++){
        printf("# Produto %d\n", i+1);
        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[i].codigo);
        printf("Digite o nome do produto: ");
        scanf(" %14[^\n]", produtos[i].nome);
        printf("Digite o preco do produto: ");
        scanf("%f", &produtos[i].preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produtos[i].quantidade);
        printf("\n");
    }
}
void ler_pedido(int *codigo_pedido, int *quantidade_pedido){
    printf("Digite o codigo do produto: ");
    scanf("%d", codigo_pedido);
    if(*codigo_pedido != 0){
    printf("Digite a quantidade desejada: ");
    scanf("%d", quantidade_pedido);
    }
}
void verificar_estoque(Produto produtos[5], int total, int *codigo_pedido, int *quantidade_pedido){
    int produto_encontrado = 0;
    if(*quantidade_pedido <= 0){
        printf("Erro: a quantidade precisa ser maior que zero!\n");
        return;
    }
    for(int i = 0; i < total; i++){
        if(produtos[i].codigo == *codigo_pedido){
                produto_encontrado = 1;
                if(*quantidade_pedido > produtos[i].quantidade){
                    printf("Nao ha estoque suficiente para a quantidade desejada!\n");
                }
                else{
            produtos[i].quantidade -= *quantidade_pedido;
            printf("Pedido realizado com sucesso!\n");
            printf("Quantidade apos o pedido: %d\n", produtos[i].quantidade);
            }
            break;
          }
        }
            if(produto_encontrado != 1){
            printf("Produto nao encontrado!\n");
    }
}
int main(){
    int codigo_pedido, quantidade_pedido;
cabecalho();
Produto produtos[5];
ler_produtos(produtos, 5);
    do{
       ler_pedido(&codigo_pedido, &quantidade_pedido);
    if(codigo_pedido !=0){
        verificar_estoque(produtos, 5, &codigo_pedido, &quantidade_pedido);
    }
    }while(codigo_pedido != 0);
    return 0;
}
