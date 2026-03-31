#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que lê dois números e que pergunta qual a
operação você quer realizar. Você pode escolher soma(0),
subtração(1), multiplicação(2) ou divisão(3).Exiba o resultado da
operação escolhida ou uma mensagem dizendo que a operação
escolhida não é válida.
*/

float calculadora(int operacao, float numero1, float numero2)
{
    if (operacao == 0)
    {
        return numero1 + numero2;
    }
    else if (operacao == 1)
    {
        return numero1 - numero2;
    }
    else if (operacao == 2)
    {
        return numero1 * numero2;
    }
    else if (operacao == 3)
    {
        return numero1 / numero2;
    }
}

int main()
{
    int operacao;
    float numero1, numero2;

    printf("Calculadora básica. Escolha um tipo de operacao, insira dois numeros e exibirei o resultado.\n");

    printf("\n[0] Soma");
    printf("\n[1] Subtracao");
    printf("\n[2] Multiplicacao");
    printf("\n[3] Divisao\n");

    printf("\nEscolha a operacao: ");
    scanf("%d", &operacao);

    if (operacao < 0 || operacao > 3)
    {
        printf("\nVoce nao escolheu uma operacao valida.\n");
        return 0;
    }

    printf("\nNumero 1: ");
    scanf("%f", &numero1);

    printf("Numero 2: ");
    scanf("%f", &numero2);

    if (operacao == 3 && numero2 == 0)
    {
        printf("\nResultado da operacao: Indeterminado.\n");
        return 0;
    }

    printf("\nResultado da operacao: %.2f\n", calculadora(operacao, numero1, numero2));

    return 0;
}
