#include <stdio.h>

void potencia(int a, int b) {
    int resultado = 1;
    for(int i = 0; i < b; i++) {
        resultado = resultado * a;
    }

    printf("O resultado é %d\n", resultado);
}

void potencia2(int* resultado, int a, int b) {
    *resultado = 1;
    for(int i = 0; i < b; i++) {
        (*resultado) = (*resultado) * a;
    }
}

void main() {
    int primeironumero;
    int segundonumero;

    printf("Informe um número: ");
    scanf("%d", &primeironumero);

    printf("\n");

    printf("Informe a potência: ");
    scanf("%d", &segundonumero);

    printf("\n");
    printf("Vamos calcular %d elevado a %d:\n\n", primeironumero, segundonumero);

    potencia(primeironumero, segundonumero);

    // usando ponteiro
    int resultado;
    potencia2(&resultado, primeironumero, segundonumero);
    printf("O segundo resultado é %d\n", resultado);
}