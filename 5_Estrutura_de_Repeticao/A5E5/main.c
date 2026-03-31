#include <stdio.h>
#include <stdlib.h>

/*
Implemente o problema do número Fatorial de forma iterativa
(utilize while, for ou do-while). Neste exercício você não usará
recursão, mas poderá comparar os duas técnicas e entender
melhor quando utilizar recursão.
*/

int main()
{
    int numero, i;

    printf("Digite um numero inteiro e retornarei o seu fatorial.\n");

    printf("\nNumero: ");
    scanf("%d", &numero);

    for (i = (numero - 1); i > 0; i--)
    {
        numero = numero * i;
    }

    printf("\nResultado: %d\n", numero);

    return 0;
}
