/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/23 12:15:07 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buff;
	int				i;
	static int		line = 0;
	int				j;
	int				h;
	char			*str;

	j = 0;
	if (line == 0)
	{
		buff = malloc (BUFFER_SIZE);
		j = read(fd, buff, BUFFER_SIZE);
	}
		// buff = malloc (BUFFER_SIZE);
		// j = read(fd, buff, BUFFER_SIZE);
	str = malloc (j + 1);
	j = 0;
	i = 0;
	while (j <= line)
	{
		h = 0;
		while (buff[i] != '\n' && buff[i])
		{
			str[h] = buff[i];
			i++;
			h++;
		}
		str[h] = buff[i];
		str[h + 1] = '\0';
		i++;
		printf("hau da j %d\n", j);
		j++;
	}
	line++;
	return (str);
}

int main()
{
	int	p;

	p = open("kaixo.txt", O_RDONLY);
	printf(" %s\n", get_next_line(p));
	printf(" %s\n", get_next_line(p));
	printf(" %s\n", get_next_line(p));
	printf(" %s\n", get_next_line(p));
	


}
