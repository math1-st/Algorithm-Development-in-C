#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que solicita do usuário uma quantidade
de dias, horas, minutos e segundos. Calcule o total convertido
em somente segundos e mostre o resultado.
*/

int main()
{
    int dias, horas, minutos, segundos, total_em_segundos;

    printf("Insira uma quantidade de horas, minutos e segundos, e exibirei o total de segundos.\n");

    printf("\nDias: ");
    scanf("%d", &dias);

    printf("\nHoras: ");
    scanf("%d", &horas);

    printf("\nMinutos: ");
    scanf("%d", &minutos);

    printf("\nSegundos: ");
    scanf("%d", &segundos);

    total_em_segundos = (dias * 24 * 3600) + (horas * 3600) + (minutos * 60) + segundos;

    printf("\nTotal em Segundos: %d\n", total_em_segundos);



    return 0;
}
