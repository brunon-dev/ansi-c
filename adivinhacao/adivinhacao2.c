#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // imprime cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    // recupera o número de segundos a partir de 01/01/1970 EPOCH Time
    int segundos = time(0);
    // muda a semente do rand - s do srand é de seed
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    int numerodetentativas = 5;

    for (int i = 1; i <= numerodetentativas; i++){
        printf("Tentativa %d de %d\n", tentativas, numerodetentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        
        if(chute < 0){
            printf("Você não pode chutar números negativos!\n");
            i--;
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou){
            break;
        } else if (maior){
            printf("Seu chute foi maior que o número secreto!\n");
        } else {
            printf("Seu chute foi menor que o número secreto!\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if(acertou){
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.2f\n", pontos);
    } else {
        printf("Você perdeu! O número secreto era %d! Tente de novo!\n", numerosecreto);
    }
}