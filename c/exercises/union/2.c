/*
Questão 2:
Considere a seguinte declaração de union:
union Informacao {
    int codigo;
    float preco;
    char nome[30];
};
Escreva um programa que utilize a union Informacao para armazenar e exibir
diferentes tipos de informações de um produto.
O programa deve:
1. Declarar uma variável do tipo union Informacao.
2. Atribuir um código inteiro ao campo codigo e exibir esse valor.
3. Atribuir um preço ao campo preco e exibir esse valor com duas casas decimais.
4. Atribuir o nome de um produto ao campo nome e exibir esse nome.
5. Mostrar o tamanho da union Informacao utilizando:sizeof(union Informacao)
6. Após cada atribuição, exiba o valor armazenado naquele campo, para deixar claro
que a union pode armazenar diferentes tipos de dados, mas utiliza o mesmo espaço de memória.
*/
#include <stdio.h>
#include <string.h>
union Informacao {
    int codigo;
    float preco;
    char nome[30];
};
int main(){
    union Informacao info;
    info.codigo = 5;
    printf("Codigo: %d\n", info.codigo);
    info.preco = 9.90;
    printf("Preco: R$%.2f\n", info.preco);
    strcpy(info.nome, "Abacaxi");
    printf("Nome: %s\n", info.nome);
    printf("Tamanho: %zu bytes\n", sizeof(union Informacao));
    return 0;
}
