#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função recursiva para cálculo de potência:
pot(base, expoente) que, quando invocada, retorna base^expoente.
Exemplo:
pot(3, 4) = 3 * 3 * 3 * 3
Suponha que o expoente seja um número inteiro maior ou igual a 1.
Dica: A etapa de recursão pode usar o relacionamento:
base exponente = base * base^exponente – 1
a condição final ocorre quando o expoente é igual a 1
*/

int pot(int base, int expoente)
{

    if (expoente == 1)
    {
        return base;
    }
    else
    {
        return base * pot(base, expoente - 1);
    }
}

int main()
{
    int base, expoente;
    printf("Digite uma base e um expoente e retornarei o resultado da potenciacao.\n");

    printf("\nBase: ");
    scanf("%d", &base);

    printf("Expoente: ");
    scanf("%d", &expoente);

    printf("\nResultado: %d\n", pot(base, expoente));

    return 0;
}
