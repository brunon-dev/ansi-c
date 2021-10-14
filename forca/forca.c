#include <stdio.h>
#include <string.h>

int main(){
    char palavrasecreta[20];

    // joga o conteúdo da string no array de char
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;
    do {
        for(int i = 0; i < strlen(palavrasecreta); i++) {
            int achou = 0;
            for (int j = 0; j < tentativas; j++){
                if(chutes[j] == palavrasecreta[i]) {
                    achou = 1;
                    break;
                }
            }
            if (achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;

        printf("Qual é a letra? ");
        scanf(" %c", &chute);  // no %c precisa do espaço antes para desconsiderar o "Enter" depois da letra
        
        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou);

}