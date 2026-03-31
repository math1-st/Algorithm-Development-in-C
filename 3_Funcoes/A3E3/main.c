#include <stdio.h>
#include <stdlib.h>

/*
Crie uma função void modifica (int *x), que deve mudar o valor
passado como parâmetro para o próximo inteiro ímpar. Ex: para a
variável inteira a, a=5; modifica(&a); fará com que o valor de a se
torne 7; a=2; modifica(&a); fará com que o valor de a se torne 3.
*/

void modifica (int *x)
{
    if (*x % 2 == 0)
    {
        *x += 1;
    }
    else
    {
        *x += 2;
    }
}

int main()
{
    int inteiro;

    printf("Insira um numero inteiro e exibirei o inteiro impar mais proximo.\n");

    printf("\nNumero inteiro: ");
    scanf("%d", &inteiro);

    modifica(&inteiro);
    printf("\nImpar mais proximo: %d\n", inteiro);

    return 0;
}
