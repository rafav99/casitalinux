char *ft_strncat(char *dest, char *src, unsigned int n)
{
    char *ptr;

    ptr = dest;
    while (*ptr != '\0')
        ptr++;
    while (n > 0 && *src != '\0') 
    {
        *ptr = *src;
        ptr++;
        src++;
        n--;
    }
    *ptr = '\0';
    return dest;
}