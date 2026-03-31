#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
1. Implemente uma função float potencia(float x, int n) que devolva o
valor de x elevado a n.
*/

float potencia(float x, int n)
{
    return pow(x, n);
}

int main()
{
    float numero, resultado;
    int expoente;

    printf("Insira um numero e um expoente e irei exibir o resultado da potencia.\n");

    printf("\nNumero: ");
    scanf("%f", &numero);

    printf("Expoente: ");
    scanf("%d", &expoente);

    resultado = potencia(numero, expoente);

    printf("\nResultado da Potencia: %.2f\n", resultado);

    return 0;
}
