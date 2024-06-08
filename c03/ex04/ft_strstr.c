#include <stddef.h>

char *my_strstr(char *str, char *to_find)
{
    const char *h;
    const char *n;

    if (*to_find == '\0')
        return str;
    while (*str != '\0') 
    {
        h = str;
        n = to_find;
        while (*h == *n && *n != '\0')
        {
            h++;
            n++;
        }
        if (*n == '\0')
            return (str);
        str++;
    }
    return (NULL);
}