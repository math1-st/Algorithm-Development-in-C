#include <stdio.h>
#include <stdlib.h>

/*
Uma loja fornece sempre 5% de desconto para os seus
funcionários. A loja fornece também 3% de desconto para clientes
que comprem mais do que R$ 1.000,00.Faça um programa que
calcule o valor total a ser pago por uma pessoa.O programa
deverá ler o valor total da compra efetuada e um código que
identifique se o comprador é um cliente comum (1) ou um
funcionário (2).
*/

int main()
{
    int cliente_ou_funcionario;
    float carrinho, desconto;

    printf("Identifique se voce e cliente ou comprador e exibirei o preco total de sua compra.\n");

    printf("\nVoce e cliente [1] ou funcionario [2]: ");
    scanf("%d", &cliente_ou_funcionario);

    if (cliente_ou_funcionario < 1 || cliente_ou_funcionario > 2)
    {
        printf("\nVoce nao se identificou corretamente.\n");
        return 0;
    }

    printf("\nInsira quanto deu sua compra ate agora: ");
    scanf("%f", &carrinho);

    if (cliente_ou_funcionario == 1)
    {
        desconto = (carrinho > 1000)? 0.97 : 1;
    }
    else if (cliente_ou_funcionario == 2)
    {
        desconto = (carrinho > 1000)? 0.92 : 0.95;
    }

    printf("\nValor total da compra: %.2f\n", carrinho * desconto);

    return 0;
}
