#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou() {
    return 0;
}

void move(char direcao) {
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao)
    {
        case 'a':
            // move para esquerda
            heroi.y--;
            break;
        case 'w':
            // move para cima
            heroi.x--;
            break;
        case 's':
            // move para baixo
            heroi.x++;
            break;
        case 'd':
            // move para direita
            heroi.y++;
            break;
    }

    m.matriz[heroi.x][heroi.y] = '@';
}

int main() {
    
    lemapa(&m);
    encontranomapa(&m, &heroi, '@');

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while(!acabou());

    liberamapa(&m);
}