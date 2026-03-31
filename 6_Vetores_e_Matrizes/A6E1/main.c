#include <stdio.h>
#include <stdlib.h>

/*
Crie um programa em C que peça 10 números reais, armazene-os
em um vetor e diga qual é o índice do maior, e seu valor.
*/

int main()
{
    int i, indice;
    float vetor[10], numero, maior = 0;

    printf("Insira 10 numeros e lhe mostrarei o maior numero inserido e seu indice.\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("Numero %d: ", i+1);
        scanf("%f", &numero);

        vetor[i] = numero;
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            indice = i;
        }
    }

    printf("\nMaior Numero: %.1f - Indice: %d\n", maior, indice);

    return 0;
}
