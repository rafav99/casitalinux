int ft_strcmp(char *s1, char *s2)
{
    unsigned char *help1;
    unsigned char *help2;

    help1 = (unsigned char *)s1;
    help2 = (unsigned char *)s2;

    while (*help1 != '\0' && *help2 != '\0')
    {
        if (*help1 != *help2) 
            return (*help1 - *help2);
        help1++;
        help2++;
    }
    return (*help1 - *help2);
}