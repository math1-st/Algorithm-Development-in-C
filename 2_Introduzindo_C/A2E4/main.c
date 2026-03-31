#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que pergunte a quantidade de km
percorridos por um carro alugado, assim como a quantidade
de dias pelos quais o carro foi alugado. Calcule e mostre o
preço a pagar, sabendo que o carro custa R$ 60,00 por dia e
R$ 0,15 por km rodado.
*/

int main()
{

    float km_percorridos, dias_alugados, total_aluguel;

    printf("Insira quantos km o carro alugado correu, quantos dias foram alugados e exibirei o preco total a pagar pelo aluguel.\n");

    printf("\nKM percorridos: ");
    scanf("%f", &km_percorridos);

    printf("Dias alugados: ");
    scanf("%f", &dias_alugados);

    total_aluguel = (dias_alugados * 60) + (km_percorridos * 0.15);

    printf("\nPreco total do aluguel do carro: %.2f\n", total_aluguel);

    return 0;
}
