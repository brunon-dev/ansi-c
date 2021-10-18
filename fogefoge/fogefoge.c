#include <stdio.h>
#include <stdlib.h>

int main() {
    // matriz de 5 x 10
    // declara com "10+1" porque toda string tem um 0 no último caracter
    // como vamos ler a string do arquivo de mapa, precisamos considerar isso
    char mapa[5][10+1];

    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("%s\n", mapa[i]);
    }

    fclose(f);
}