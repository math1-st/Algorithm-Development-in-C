#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que pergunte a distância que um
passageiro deseja percorrer em km. Calcule o preço da
passagem, cobrando R$ 0,50 por km para viagens até 200 km e
R$ 0,45 para viagens mais longas.
*/

int main()
{
    int distancia_km;
    float valor_por_km;

    printf("Insira a distancia que voce deseja percorrer em km e exibirei o preco total.\n");
    printf("(Ate 200km: R$0.50 por km. Mais que 200km: R$0.45)\n");

    printf("\nDistancia em KM: ");
    scanf("%d", &distancia_km);

    valor_por_km = (distancia_km <= 200)? 0.50 : 0.45;

    printf("\nPreco total da passagem: %.2f\n", distancia_km * valor_por_km);


    return 0;
}
