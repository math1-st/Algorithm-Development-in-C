#include <stdio.h>
#include <stdlib.h>

/*
Solicitar dados de uma matriz 4x4 e montar um vetor de 4
elementos com a soma dos elementos ímpares de cada linha
*/

int main()
{
    int matriz[4][4], linha, coluna, vetor[4] = {0, 0, 0, 0};

    printf("Insira numeros para matriz 4x4 e exibirei a soma dos elementos impares de cada linha em um vetor.\n\n");

    for (linha = 0; linha < 4; linha++)
    {
        for (coluna = 0; coluna < 4; coluna++)
        {
            printf("Elemento [%d][%d]: ", linha+1, coluna+1);
            scanf("%d", &matriz[linha][coluna]);

            if (matriz[linha][coluna] % 2 != 0)
            {
                vetor[linha] += matriz[linha][coluna];
            }
        }
    }

    printf("\nVetor:");
    for (linha = 0; linha < 4; linha++)
    {
        printf("%3d", vetor[linha]);
    }

    printf("\n");

    return 0;
}
