int ft_iterative_power(int nb, int power)
{
    int i;
    int result;

    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    result = 1;
    i = 0;
    while(i < power)
    {
        result = result * nb;
        i++;
    }
    return (result);
}