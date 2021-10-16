#include <stdio.h>

void abertura(int m) {
    printf("Tabuda do %d:\n\n", m);
}

// retorna a soma de itens de um array
int soma(int nums[3], int tamanho) {
    int resultado = 0;
    for(int i=0; i<tamanho; i++) {
        resultado += nums[i];
    }
    return resultado;
}

void main() {
    int multiplicador = 2;

    abertura(multiplicador);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", multiplicador, i, multiplicador * i);
    }

    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    int total = soma(nums, 3);
    printf("O resultado da soma é %d\n", total);
}