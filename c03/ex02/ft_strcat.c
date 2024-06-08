char *ft_strcat(char *dest, char *src) 
{
    char *ptr;
    
    ptr = dest;
    while (*ptr != '\0') 
        ptr++;
    while (*src != '\0') 
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return (dest);
}