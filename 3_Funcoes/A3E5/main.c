#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

/*
Implemente uma calculadora básica utilizando funções
organizadas em arquivos separados. Crie os arquivos
calculadora.h, calculadora.c e main.c. A calculadora deve
implementar as operações de soma, subtração, multiplicação e
divisão, além de validar a divisão por zero.
*/

int main()
{
    float numero1, numero2, resultado;

    printf("Calculadora Basica. Insira dois numeros e retornarei os resultados das quatro operacoes basicas.\n");

    printf("\nNumero 1: ");
    scanf("%f", &numero1);

    printf("Numero 2: ");
    scanf("%f", &numero2);

    printf("\nResultado Soma: %.2f", soma(numero1, numero2));
    printf("\nResultado Subtracao: %.2f", subtracao(numero1, numero2));
    printf("\nResultado Multiplicacao: %.2f", multiplicacao(numero1, numero2));

    if (numero2 == 0)
    {
        printf("\nResultado Divisao: Indeterminado.\n");
    }
    else
    {
        printf("\nResultado Divisao: %.2f\n", divisao(numero1, numero2));
    }

    return 0;
}
