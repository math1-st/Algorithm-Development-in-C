#include <stdio.h>
#include <stdlib.h>

/*
Crie uma função para calcular e retornar o peso de uma pessoa nos
outros planetas do Sistema Solar. A função deve ter dois parâmetros: o
planeta desejado e o peso em Kg da pessoa na Terra. O programa
principal deve receber o peso da pessoa na Terra (em Kg) e o planeta
desejado.

Relação de pesos: 1 Kg na Terra equivale a: 0.37 Kg em Mercúrio; 0.88 Kg
em Vênus; 0.38 Kg em Marte; 2.64 Kg em Júpiter; 1.15 Kg em Saturno; 1.17
Kg em Urano; e 1.18 Kg em Netuno.
*/

float peso_em_outro_planeta(int planeta_desejado, float peso_na_terra)
{
    float relacao_peso;

    if (planeta_desejado == 1)
    {
        relacao_peso = 0.37;
    }
    else if (planeta_desejado == 2)
    {
        relacao_peso = 0.88;
    }
    else if (planeta_desejado == 3)
    {
        relacao_peso = 0.38;
    }
    else if (planeta_desejado == 4)
    {
        relacao_peso = 2.64;
    }
    else if (planeta_desejado == 5)
    {
        relacao_peso = 1.15;
    }
    else if (planeta_desejado == 6)
    {
        relacao_peso = 1.17;
    }
    else if (planeta_desejado == 7)
    {
        relacao_peso = 1.18;
    }

    return peso_na_terra * relacao_peso;
}

int main()
{
    int planeta_desejado;
    float peso_na_terra, peso_novo;

    printf("Escolha um planeta do sistema solar (1-7) e insira um peso em KG para descobrir o peso no planeta.\n");

    printf("\n[1] Mercurio");
    printf("\n[2] Venus");
    printf("\n[3] Marte");
    printf("\n[4] Jupiter");
    printf("\n[5] Saturno");
    printf("\n[6] Urano");
    printf("\n[7] Netuno\n");

    printf("\nPlaneta desejado: ");
    scanf("%d", &planeta_desejado);

    if (planeta_desejado <= 0 || planeta_desejado > 7)
    {
        printf("\nVoce nao escolheu um planeta dentro das opcoes.\n");
        return 0;
    }

    printf("Peso em KG: ");
    scanf("%f", &peso_na_terra);

    peso_novo = peso_em_outro_planeta(planeta_desejado, peso_na_terra);

    printf("\nPeso novo: %.2f\n", peso_novo);

    return 0;
}
