#include <stdio.h>
#include <stdlib.h>

/*
Faca um programa que imprima os números de 1 a 50 de 1 em 1 e
de 52 a 100 de 2 em 2.
*/

int main()
{
    int numero;

    for (numero = 1; numero <= 50; numero++)
    {
        printf("%d\n", numero);
    }

    for (numero = 52; numero <= 100; numero += 2)
    {
        printf("%d\n", numero);
    }

    return 0;
}
