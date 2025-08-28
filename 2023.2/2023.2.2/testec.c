#include <stdio.h>

float func(float a, float b) {
    float main = a / b;
    return main;
}

int main() {
    float main = 0;
    float valor1;
    float valor2;
    scanf("%f", & valor1);
    scanf("%f", & valor2);

    main = func(valor1, valor2);
    printf("divisao %f\n", main);
}
