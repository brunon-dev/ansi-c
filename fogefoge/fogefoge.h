#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
void fantasmas();
int acabou();
int ehdirecao(char direcao);
void move(char direcao);
void explodepilula();
void executaexplosao(int x, int y, int somax, int somay, int qtd);