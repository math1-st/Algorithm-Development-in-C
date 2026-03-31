#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que solicita dois números inteiros ao
usuário e armazene cada um destes números em variáveis
distintas. Realize então uma troca de valores entre as
variáveis. Exiba, no fim, os valores de cada variável.

Exemplo:
Entrada: a = 9; b= 2; Saída: b= 2; a = 9
*/

int main()
{
    int numero1, numero2, numero3;

    printf("Insira dois numeros e trocarei o valor de cada variavel entre si.\n");

    printf("\nNumero 1: ");
    scanf("%d", &numero1);

    printf("Numero 2: ");
    scanf("%d", &numero2);

    numero3 = numero1;
    numero1 = numero2;
    numero2 = numero3;

    printf("\nResultado:\n");

    printf("\nNumero 1: %d", numero1);
    printf("\nNumero 2: %d\n", numero2);

    return 0;
}
