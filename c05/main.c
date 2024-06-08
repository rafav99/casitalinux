#include <stdio.h>

int ft_iterative_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_factorial(int nb);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);



int main()
{
    printf("el factorial it de 5 es %i\n", ft_iterative_factorial(5));
    printf("el factorial rec de 5 es %i\n", ft_recursive_factorial(5));
    printf("0 elevado a 0 it es %i\n", ft_iterative_power(0, 0));
    printf("0 elevado a 0 rec es %i\n", ft_recursive_power(0, 0));
    printf("La sucesión de fibonacci en el índice 7 es  %i\n", ft_fibonacci(7));
}