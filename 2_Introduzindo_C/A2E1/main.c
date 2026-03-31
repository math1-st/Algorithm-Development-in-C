#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa em C que solicita do usuário dois
números reais, então some os dois números e exiba o
resultado.
*/

int main()
{

    printf("Insira dois numeros e exibirei o resultado da soma entre eles.\n");

    float numero1, numero2, resultado_soma;

    printf("\nNumero 1: ");
    scanf("%f", &numero1);

    printf("\nNumero 2: ");
    scanf("%f", &numero2);

    resultado_soma = numero1 + numero2;

    printf("\nResultado da Soma: %.2f\n", resultado_soma);

    return 0;
}
