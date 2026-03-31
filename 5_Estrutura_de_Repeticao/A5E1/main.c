#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que calcula a média aritmética de 5
números digitados pelo usuário. Utilize contadores e
acumuladores.
*/

int main()
{
    int i,  contador = 0;
    float numero, acc = 0;

    printf("Insira 5 numeros e exibirei a media simples.\n\n");

    for (i = 0; i < 5; i++)
    {
        printf("Digite o %do numero: ", i+1);
        scanf("%f", &numero);

        acc += numero;
        contador += 1;
    }

    printf("\nMedia simples dos 5 numeros: %.2f\n", acc / contador);

    return 0;
}
