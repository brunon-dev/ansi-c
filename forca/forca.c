#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
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

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
                                 (erros >= 1 ? '_' : ' '),
                                 (erros >= 1 ? ')' : ' '));

    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
                                 (erros >= 2 ? '|' : ' '),
                                 (erros >= 3 ? '/' : ' '));

    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));

    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
                                 (erros >= 4 ? '\\' : ' '));

    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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

void adicionapalavra(){
    char queradicionar;

    printf("Você deseja adiconar uma nova palavra ao jogo? (S/N) ");
    scanf(" %c", &queradicionar);

    if(queradicionar == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;
        // abre com permissão de leitura E escrita ("r+")
        f = fopen("palavras.txt", "r+");

        if (f == 0) {
            printf("Desculpe, banco de dados não disponível!\n\n");
            exit(1);
        }

        // lê a quantidade de palavras na primeira linha do arquivo
        int qtdepalavras;
        fscanf(f, "%d", &qtdepalavras);
        qtdepalavras++;

        // posiciona novamente na primeira linha do arquivo e sobreescreve a quantidade de palavras adicionando 1
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtdepalavras);

        // posiciona na última linha do arquivo e escreve a nova palavra
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra(){
    // joga o conteúdo da string no array de char
    //sprintf(palavrasecreta, "MELANCIA");

    FILE* f;
    // abre apenas com permissão de leitura ("r")
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

int chuteserrados() {
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
    return erros;
}

int enforcou() {
    int erros = chuteserrados();

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

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    
    adicionapalavra();

}