#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Escreva uma função que tenha os comprimentos dos dois lados
mais curtos de um triângulo retângulo como seus parâmetros.
Retorne a hipotenusa do triângulo, calculada usando o teorema de
Pitágoras, como o resultado da função. Inclua um programa
principal que lê os comprimentos dos lados mais curtos de um
triângulo retângulo do usuário e use sua função para calcular o
comprimento da hipotenusa. Exiba o resultado. Utilize a função do
exercício anterior.
*/

float potencia(float x, int n)
{
    return pow(x, n);
}

int main()
{
    float menor_lado1, menor_lado2, soma_catetos, hipotenusa;

    printf("Insira o primeiro e o segundo menores lados de um triangulo e exibirei a hipotenusa.\n");

    printf("\nPrimeiro menor lado: ");
    scanf("%f", &menor_lado1);

    printf("Segundo menor lado: ");
    scanf("%f", &menor_lado2);

    soma_catetos = potencia(menor_lado1, 2) + potencia(menor_lado2, 2);

    hipotenusa = sqrt(soma_catetos);

    printf("\nHipotenusa: %.2f\n", hipotenusa);

    return 0;
}
