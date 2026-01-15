/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:43:23 by smargaro          #+#    #+#             */
/*   Updated: 2026/01/15 15:40:39 by smargaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	*get_next_line(int fd)
{
	char	temp[4];
	int	fine_lettura;
	static char	*memory;
	void	*posizione;

	if (!memory)
		memory = NULL;
	while (fine_lettura = read(fd, temp, 3))
	{
		temp[fine_lettura] = '\0';
		salvataggio (memory, temp);
			if (posizione=strchr(memory, '\n'))
			{
				funz salva e ritorna; // posso creare funzione che crea variabile r, salva avanzo, ritorna r
				return (r);
			}
	}
	if (!memory)
		return (NULL);
	else // non ci sono \n in memoria e non c'e altro da leggere
		fai funzione copia di memory non static, poi libera memory;
		return (copia di memory);
}
