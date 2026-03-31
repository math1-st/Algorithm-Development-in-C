#include <stdio.h>
#include <stdlib.h>

/*
Faca um programa que leia 6 números inteiro positivos do usuário
exiba o maior o numero lido.
*/

int main()
{
    float numero, maior = 0;
    int i;

    printf("Insira 6 numeros e lhe mostrarei o maior numero inserido.\n\n");

    for (i = 0; i < 6; i++)
    {
        printf("Digite o %do numero: ", i+1);
        scanf("%f", &numero);

        if (numero > maior) {maior = numero;}
    }

    printf("\nMaior numero inserido: %.1f\n", maior);
    return 0;
}
