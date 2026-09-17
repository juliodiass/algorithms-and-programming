#include <stdio.h>
void atualizarmenor(int *a, int *b, int c){
    if(*a > *b){
        *b = c;
    }
    else{
        *a = c;
    }
}

int main(){
    int a, b, c;
    printf("Digite 2 numeros inteiros: ");
    scanf("%d %d", &a, &b);
    printf("Os valores antes sao: %d %d\n", a, b);
    printf("Digite um novo valor: ");
    scanf("%d", &c);
    atualizarmenor(&a, &b, c);

    printf("Os valores depois sao: %d %d\n", a, b);
    return 0;
}
