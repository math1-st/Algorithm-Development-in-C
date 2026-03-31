#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que imprime uma sequência de 5 números
em ordem inversa à da leitura.
*/

int main()
{
    int i;
    float vetor[5];

    printf("Insira 5 numeros e exibirei a ordem inversa.\n\n");

    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i+1);
        scanf("%f", &vetor[i]);
    }

    for (i = 4; i >= 0; i--)
    {
        printf("\n%.1f", vetor[i]);
    }

    printf("\n");

    return 0;
}
