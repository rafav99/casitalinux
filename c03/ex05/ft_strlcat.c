unsigned int	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	unsigned int	tik;

	ptr = dest + ft_strlen(dest);
	tik = ft_strlen(dest);
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	while (tik < size - 1 && *src != '\0' && size >= 2)
	{
		*ptr = *src;
		ptr++;
		src++;
		tik++;
	}
	if (size != 0)
		*ptr = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}