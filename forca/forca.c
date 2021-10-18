#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura(){
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n");
}

void chuta() {
    char chute;

    printf("Qual é a letra? ");
    scanf(" %c", &chute);  // no %c precisa do espaço antes para desconsiderar o "Enter" depois da letra

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca(){
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        int achou = achouchute(palavrasecreta[i]);
        
        if (achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra(){
    // joga o conteúdo da string no array de char
    //sprintf(palavrasecreta, "MELANCIA");

    FILE* f;
    f = fopen("palavras.txt", "r");

    if (f == 0) {
        printf("Desculpe, banco de dados não disponível!\n\n");
        exit(1);
    }

    int qtdepalavras;
    fscanf(f, "%d", &qtdepalavras);

    srand(time(0));
    int randomico = rand() % qtdepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!achouchute(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }
    return erros >= 5;
}

int achouchute(char letra) {
    int achou = 0;
    for (int j = 0; j < chutesdados; j++){
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void main(){
    abertura();
    
    escolhepalavra();

    do {
        desenhaforca();

        chuta();

    } while (!acertou() && !enforcou());

}