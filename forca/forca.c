#include <stdio.h>
#include <string.h>

int main(){
    char palavrasecreta[20];

    // joga o conteúdo da string no array de char
    sprintf(palavrasecreta, "MELANCIA");

    /*
    printf("%s\n", palavrasecreta);

    // para tratar o array de char como uma string, ao final do conteúdo ele coloca o "\0" indicando que não tem mais conteúdo
    printf("O char da posição 7 é %c - é o fim da string? %d\n", palavrasecreta[7], palavrasecreta[7] == 0);
    printf("O char da posição 8 é %c - é o fim da string? %d\n", palavrasecreta[8], palavrasecreta[8] == 0);
    */

    int acertou = 0;
    int enforcou = 0;
    int tentativa = 1;

    do {
        // começar nosso jogo
        char chute;
        printf("Tentativa %d - Informe uma letra: ", tentativa);
        scanf("%c", &chute);

        for(int i = 0; i < strlen(palavrasecreta); i++) {
            if (palavrasecreta[i] == chute){
                printf("A posição %d tem essa letra!\n", i);
            }
        }
        tentativa++;
    } while(!acertou && !enforcou);

}