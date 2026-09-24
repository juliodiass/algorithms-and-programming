void move(char direcao);
int acabou(void);
int ehdirecao(char direcao);
int ehvalida(MAPA *m, int x, int y);
int ehvazia(MAPA *m, int x, int y);
void andando(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino);