#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa para receber uma matriz 3x3 (solicitar ao
usuário) e apresentar a soma dos elementos da diagonal
principal e a matriz na forma como deve ser vista: com linhas e
colunas.
*/

int main()
{
    int matriz[3][3], linha, coluna, soma_diagonal_principal = 0;
    printf("Insira valores para uma matriz 3x3 e exibirei a soma dos elementos da diagonal principal e a matriz completa.\n\n");

    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("Elemento [%d][%d]: ", linha+1, coluna+1);
            scanf("%d", &matriz[linha][coluna]);

            if (linha == coluna) {soma_diagonal_principal += matriz[linha][coluna];}
        }
    }

    printf("\nSoma dos elementos da diagonal principal: %d\n\n", soma_diagonal_principal);

    printf("Matriz 3x3 completa:\n");
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("%3d", matriz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
