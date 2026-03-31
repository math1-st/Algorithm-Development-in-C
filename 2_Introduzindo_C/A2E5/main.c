#include <stdio.h>
#include <stdlib.h>

/*
Tendo como dados de entrada a altura de uma pessoa,
construa um algoritmo que calcule seu peso ideal, usando a
seguinte fórmula: (72.7*altura) -58. Imprima o resultado.
*/

int main()
{
    float altura_pessoa, resultado;

    printf("Insira uma altura em metros e te direi o peso ideal para altura inserida.\n");

    printf("\nAltura: ");
    scanf("%f", &altura_pessoa);

    resultado = (72.7 * altura_pessoa) - 58;
    printf("\nResultado do Peso Ideal: %.2f\n", resultado);


    return 0;
}
