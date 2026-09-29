// Símbolos utilizados para representar os elementos do mapa
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

// Comandos de movimentação
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

// Estrutura que representa o mapa do jogo
struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

// Estrutura que representa uma posição no mapa
struct posicao{
    int x;
    int y;
};
typedef struct posicao POSICAO;

// Lê o mapa a partir do arquivo
void lermapa(MAPA* m);

// Aloca a memória necessária para armazenar o mapa
void alocamapa(MAPA* m);

// Libera a memória alocada para o mapa
void liberamapa(MAPA* m);

// Imprime o mapa na tela
void imprimemapa(MAPA* m);

// Encontra a posição de um determinado elemento no mapa
int encontramapa(MAPA *m, POSICAO *p, char c);

// Verifica se uma posição está dentro dos limites do mapa
int ehvalida(MAPA *m, int x, int y);

// Verifica se uma posição está vazia
int ehvazia(MAPA *m, int x, int y);

// Move um elemento de uma posição para outra
void andando(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino);

// Copia um mapa para outro
void copiamapa(MAPA *destino, MAPA *origem);

// Verifica se um personagem pode andar para uma determinada posição
int podeandar(MAPA *m, char personagem, int x, int y);

// Verifica se uma posição contém uma parede
int ehparede(MAPA *m, int x, int y);

// Verifica se uma posição contém determinado personagem
int ehpersonagem(MAPA *m, char personagem, int x, int y);