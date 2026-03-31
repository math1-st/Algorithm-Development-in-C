#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Faça um programa que cria uma matriz m10x15, sendo que cada
elemento é um inteiro gerado aleatoriamente. Então, exiba a
matriz completa e, na sequência, somente os elementos da
primeira coluna da matriz.
*/

int main()
{
    int matriz[10][15], i, linha, coluna, numero;
    srand(time(NULL));

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 15; coluna++)
        {
            // FORMULA NUMERO ALEATORIO: numero = (rand() % (MAX - MIN + 1)) + MIN;
            numero = (rand() % (100 - 1 + 1)) + 1;
            matriz[linha][coluna] = numero;
            printf("%3d", matriz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    for (linha = 0; linha < 10; linha ++)
    {
        printf("%3d", matriz[linha][0]);
    }

    printf("\n");

    return 0;
}
