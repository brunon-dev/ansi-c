#define HEROI '@'
#define VAZIO '.'
#define FANTASMA 'F'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int podeandar(MAPA* m, char personagem, int x, int y);
int encontranomapa(MAPA* m, POSICAO* p, char c);
void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
