/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargaro <smargaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:43:23 by smargaro          #+#    #+#             */
/*   Updated: 2026/01/18 21:01:31 by smargaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	d;

	i = 0;
	p = ((char *) s);
	d = ((char) c);
	while (s[i])
	{
		if (d == s[i])
			return (&p[i]);
		i++;
	}
	if (d == '\0')
		return (&p[i]);
	return (NULL);
}


size_t	ft_strlen(const char *s)
{
	long int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (!count || !size)
		return (malloc(1));
	if (size >=  SIZE_MAX / count)
		return (NULL);
	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*ns;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ns = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!ns)
		return (NULL);
	ft_memcpy(ns, s1, len1);
	ft_memcpy(ns + len1, s2, len2);
	return (ns);
}

void	salvataggio(char *memory, char *temp)
{
	int a;
	int b;
	char	*provvisorio;

	a = ft_strlen(memory);
	b = ft_strlen(temp);
	provvisorio = ft_strjoin (memory, temp);
	free (memory);
	memory = ft_calloc (ft_strlen (provvisorio)+1,1);
	printf("test len %ld\n", a );
	ft_memcpy (memory, provvisorio, ft_strlen(provvisorio)+1);
	free (provvisorio);
}

char	*retline (char *memory, char *posizione)
{
	char	*r;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	printf("test1%s\n", memory);
	while (memory[i] != '\n')
		i++;
	r = ft_calloc (i + 1, sizeof(char));
	while (j < i)
	{
		r[j] = memory[j];
		j++;
	}
	salvataggio (memory, posizione);
		printf("testretl %s\n", r);
	return (r);
}

char	*get_next_line(int fd)
{
	char	temp[4];
	int	fine_lettura;
	static char	*memory;
	void	*posizione;
	char	*r;

	if (!memory)
		memory = (char *)malloc(1);
	while (fine_lettura = read(fd, temp, 3))
	{	
		temp[fine_lettura] = '\0';
		salvataggio (memory, temp);
			if (posizione = ft_strchr(memory, '\n'))
			{
				r = retline(memory, posizione); // posso creare funzione che crea variabile r, salva avanzo, ritorna r
				printf("pos %s\n", r);
				return (r);
			}
	}
	if (!memory)
		return (NULL);
	//else // non ci sono \n in memoria e non c'e altro da leggere
	//	fai funzione copia di memory non static, poi libera memory;
	//	return (copia di memory);
}


int main(void)
{
    int   fd;
    char *line;
	char *line2;

    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("ex1  %s\n", line);   
	line2 = get_next_line(fd);
    printf("ex2  %s\n", line);   
	

    return (0);
}