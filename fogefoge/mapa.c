#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {

    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

int ehvalida(MAPA* m, int x, int y) {
    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;
    
    return 1;
}

int ehvazia(MAPA* m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
}

void encontranomapa(MAPA* m, POSICAO* p, char c) {
    // acha a posição do caracter informado no mapa
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void liberamapa(MAPA* m) {
    // liberando a memória
    for(int i = 0; i < (*m).linhas; i++) {
        free((*m).matriz[i]);
    }
    // outra forma de usar o ponteiro - comparar com free na linha acima
    free(m->matriz);
}

void alocamapa(MAPA* m) {
    (*m).matriz = malloc(sizeof(char*) * (*m).linhas);
    for(int i = 0; i < (*m).linhas; i++) {
        // no caso de colunas considera o "+1" porque toda string tem a última
        // posição com valor "0" para identificar o fim da string
        (*m).matriz[i] = malloc(sizeof(char) * ((*m).colunas+1));
    }
}

void lemapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &((*m).linhas), &((*m).colunas));

    alocamapa(m);

    for(int i = 0; i < (*m).linhas; i++) {
        fscanf(f, "%s", (*m).matriz[i]);
    }
    
    fclose(f);
}

void imprimemapa(MAPA* m) {
    for(int i = 0; i < (*m).linhas; i++) {
        printf("%s\n", (*m).matriz[i]);
    }
}