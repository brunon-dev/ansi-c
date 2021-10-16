#include <stdio.h>

void potencia(int a, int b) {
    int resultado = 1;
    for(int i = 0; i < b; i++) {
        resultado = resultado * a;
    }

    printf("O resultado é %d", resultado);
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
}