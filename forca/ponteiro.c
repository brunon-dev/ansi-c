#include <stdio.h>

// parâmetro normal
void calcula(int c2) {
    printf("calcula - valor %d no endereço de memória %d\n", c2, &c2);
    c2++;
    printf("calcula - valor %d no endereço de memória %d\n", c2, &c2);
}

// recebe o ponteiro - endereço de memória
void calcula2(int* c2) {
    printf("calcula2 - valor %d no endereço de memória %d\n", (*c2), c2);
    (*c2)++;
    printf("calcula2 - valor %d no endereço de memória %d\n", (*c2), c2);
}

void soma(int* num, int a, int b) {
    (*num) = a + b;
}

void main() {
    int c = 10;

    printf("main 1 - valor %d no endereço de memória %d\n", c, &c);
    calcula(c);
    printf("main 1 - valor %d no endereço de memória %d\n", c, &c);

    printf("\n");

    printf("main 2 - valor %d no endereço de memória %d\n", c, &c);
    calcula2(&c);
    printf("main 2 - valor %d no endereço de memória %d\n", c, &c);

    printf("\n\n");
    
    int num;
    int a;
    int b;
    printf("Informe o primeiro número para soma: ");
    scanf("%d", &a);
    printf("\n");
    printf("Informe o segundo número para soma: ");
    scanf("%d", &b);
    printf("\n");
    soma(&num, a, b);
    printf("O resultado da soma é %d", num);
}