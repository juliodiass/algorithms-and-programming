#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "fogefoge.h"

MAPA m;
POSICAO heroi;

void fantasmas(){
    MAPA copia;
    copiamapa(&copia, &m);

    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA){
                if(ehvalida(&m, i, j+1) && ehvazia(&m, i, j+1)){
                    andando(&m, i, j, i, j+1);
                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou(){
    return 0;
}

int ehdirecao(char direcao){
    return direcao == CIMA || direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA;
}

void move(char direcao){

    if(!ehdirecao(direcao))
        return;

   int proximox = heroi.x;
   int proximoy = heroi.y;

    switch(direcao){
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if(!ehvalida(&m, proximox, proximoy))
        return;

    if(!ehvazia(&m, proximox, proximoy))
        return;

    andando(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}
int main(){

    lermapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do{
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();
    } while(!acabou());
    liberamapa(&m);
}
