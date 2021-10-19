#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;
int linhas;
int colunas;

void liberamapa() {
    // liberando a memória
    for(int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

void alocamapa() {
    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < linhas; i++) {
        // no caso de colunas considera o "+1" porque toda string tem a última
        // posição com valor "0" para identificar o fim da string
        mapa[i] = malloc(sizeof(char) * (colunas+1));
    }
}

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();

    for(int i = 0; i < linhas; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    
    fclose(f);
}

void imprimemapa() {
    for(int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }
}

int acabou() {
    return 0;
}

void move(char direcao) {
    int x;
    int y;

    // acha a posição do foge foge
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(mapa[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direcao)
    {
        case 'a':
            // move para esquerda
            mapa[x][y-1] = '@';
            break;
        case 'w':
            // move para cima
            mapa[x-1][y] = '@';
            break;
        case 's':
            // move para baixo
            mapa[x+1][y] = '@';
            break;
        case 'd':
            // move para direita
            mapa[x][y+1] = '@';
            break;
    }

    mapa[x][y] = '.';
}

int main() {
    
    lemapa();

    do {
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while(!acabou());

    liberamapa();
}