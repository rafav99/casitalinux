int	ft_strncmp(char *s1,char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*help1;
	unsigned char	*help2;

	help1 = (unsigned char *)s1;
	help2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (help1[i] != help2[i] || help1[i] == 0 || help2[i] == 0)
			return (help1[i] - help2[i]);
		i++;
	}
	return (0);
}