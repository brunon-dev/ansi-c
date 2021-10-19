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

int main() {
    
    lemapa();

    for(int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }

    liberamapa();
}