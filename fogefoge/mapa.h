#define HEROI '@'
#define VAZIO '.'
#define FANTASMA 'F'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void copiamapa(MAPA* destino, MAPA* origem);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void encontranomapa(MAPA* m, POSICAO* p, char c);
void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
