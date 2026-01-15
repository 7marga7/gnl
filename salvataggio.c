void	salvataggio(memory, temp)
{
	int posizione;

	if (!memory)
	{
		memory = (char *)malloc(sizeof (char) * ft_strlen(temp)+1);
		ft_memcpy (memory, temp, ft_strlen(temp)-1)
	}
	if (memory)
		ft_realloc(memory, temp);
	posizione = ft_strlen (memory);

}
