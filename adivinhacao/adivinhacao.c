#include <stdio.h>

int main(){
    // imprime cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numerosecreto = 42;

    int chute;

    printf("Qual é o seu chute? ");
    scanf("%d", &chute);
    
    int acertou = (chute == numerosecreto);

    if(acertou){
        printf("Parabéns! Você acertou!\n");
        printf("Jogue de novo! Você é um bom jogador!\n");
    } else {
        int maior = (chute > numerosecreto);
        if (maior){
            printf("Seu chute foi maior que o número secreto!\n");
        } else {
            printf("Seu chute foi menor que o número secreto!\n");
        }
    }
}