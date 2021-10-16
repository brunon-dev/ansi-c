#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura(){
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n");
}

void chuta() {
    char chute;

    printf("Qual é a letra? ");
    scanf(" %c", &chute);  // no %c precisa do espaço antes para desconsiderar o "Enter" depois da letra

    chutes[tentativas] = chute;
    tentativas++;
}

int achouchute(char letra) {
    int achou = 0;
    for (int j = 0; j < tentativas; j++){
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
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
    sprintf(palavrasecreta, "MELANCIA");
}

void main(){
    int acertou = 0;
    int enforcou = 0;
    
    escolhepalavra();

    abertura();
    
    do {
        desenhaforca();

        chuta();

    } while (!acertou && !enforcou);

}