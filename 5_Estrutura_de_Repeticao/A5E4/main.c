#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia números digitados pelo usuário.
O programa deve ler os números ate que o 0 (zero) seja
digitado.
Quando o 0 for digitado, o programa deve exibir:
⋆ a quantidade de números que foram digitados;
⋆ a somatória destes números;
⋆ e a media aritmética
*/

int main()
{
    printf("Insira numeros para exibir:\n");
    printf("\nA quantidade de numeros digitados;\n");
    printf("A somatoria destes numeros;\n");
    printf("A media simples;");
    printf("\n\n(Insira 0 para interromper)\n\n");

    int i, contador = 0;
    float numero, acc = 0;

    while (1)
    {
        printf("Digite um numero: ");
        scanf("%f", &numero);

        if (numero == 0) {break;}

        contador++;
        acc += numero;
    }

    printf("\nQuantidade de numeros digitados: %d\n", contador);
    printf("Somatoria dos numeros: %.1f\n", acc);
    printf("Media simples dos numeros: %.2f\n", acc / contador);


    return 0;
}
