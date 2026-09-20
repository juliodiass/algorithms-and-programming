/*
Questão 01
Considere a seguinte declaração de union:
union Dado {
int valor_int;
float valor_float;
char texto[20];
};
Escreva um programa que utilize a union Dado para armazenar e exibir diferentes tipos de
dados. O programa deve:
Declarar uma variável do tipo union Dado.
Atribuir um valor inteiro a valor_int e exibir esse valor.
Atribuir um valor de ponto flutuante a valor_float e exibir esse valor.
Atribuir uma sequência de caracteres a texto e exibir essa sequência.
Mostrar o tamanho da union Dado utilizando a função sizeof (com sizeof(union Dado) ) .
*/
#include <stdio.h>
#include <string.h>
union Dado {
    int valor_int;
    float valor_float;
    char texto[20];
};
int main(){
    union Dado dado;
    dado.valor_int = 10;
    printf("Numero inteiro atribuido: %d\n", dado.valor_int);
    dado.valor_float = 2.50;
    printf("Numero real atribuido: %.2f\n", dado.valor_float);
    strcpy(dado.texto, "Exercicio Union");
    printf("Texto atribuido: %s\n", dado.texto);
    printf("Tamanho: %zu bytes.\n", sizeof(union Dado));

return 0;
}
