struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;
void lermapa(MAPA* m);
void alocamapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);

