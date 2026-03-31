#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa para receber um vetor de 10 elementos (pedir
para o usuário) e apresentar: a soma dos ELEMENTOS pares e a
soma dos elementos de ÍNDICE par.
*/

int main()
{
    int i, vetor[10], soma_pares = 0, soma_indices_par = 0;

    printf("Insira 10 valores e lhe mostrarei a soma dos elementos pares e a soma dos elementos de indice par.\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("Numero %d: ", i+1);
        scanf("%d", &vetor[i]);

        if (vetor[i] % 2 == 0) {soma_pares += vetor[i];}
        if (i % 2 == 0) {soma_indices_par += vetor[i];}
    }

    printf("\nSoma dos elementos pares: %d", soma_pares);
    printf("\nSoma dos elementos de indice par: %d\n", soma_indices_par);

    return 0;
}
