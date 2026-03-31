float soma(float numero1, float numero2)
{
    return numero1 + numero2;
}

float subtracao(float numero1, float numero2)
{
    return numero1 - numero2;
}

float multiplicacao(float numero1, float numero2)
{
    return numero1 * numero2;
}

float divisao(float numero1, float numero2)
{
    if (numero2 == 0)
    {
        return 0;
    }
    else {
        return numero1 / numero2;
    }
}
