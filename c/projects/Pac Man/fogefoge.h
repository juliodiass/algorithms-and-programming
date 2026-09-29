#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

// Comandos de movimentação
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

void move(char direcao);
int acabou(void);
int ehdirecao(char direcao);
void fantasmas();
int movimentofantasma(int xatual, int yatual, int *xdestino, int *ydestino);
void explodepilula();
void explodepilula2(int novox, int novoy, int somax, int somay, int qtd);
#endif