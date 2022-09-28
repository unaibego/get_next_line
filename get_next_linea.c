/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linea.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/28 11:04:05 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;
	char			u;

	str = (char *)s;
	u = (char)c;
	i = 0;
	while (i < n)
	{
		str[i] = u;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && ((char *)src || (char *)dst))
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}


char	*memory_allocate(char *str, int h)
{
	static int i = 2;
	char 	*dst;
	
	dst = malloc(h + 1);
	dst = ft_memcpy(dst, str, h + 1);
	free(str);
	str = malloc(h + BUFFER_SIZE + 1);
	str = ft_memcpy(str, dst, h + 1);
	i++;
	return (str);
}
char	*newline(char *buff, char *str, int fd, int h, int i)
{
	int j;
	
	if (buff[i] != '\n')
	{
		j = read(fd, buff, BUFFER_SIZE);
		
		if (j <= 0)
		{
			printf("*entra aki o k*** j ==|%d|\n", j);
			return (NULL);
		}
			
		str = memory_allocate(str, h);
		buff[BUFFER_SIZE] = '\0';
		
	}
	return (str);
}
char	*save_str(char *buff, char *str, int fd)
{
	int		h;
	static int		i = 0;
	int j;
	
	h = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[h] = buff[i];
		i++;
		h++;
	}
	if (buff[i] != '\n')
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j <= 0)
			return (NULL);
		str = memory_allocate(str, h);
		buff[BUFFER_SIZE] = '\0';
		
	}
	// str = newline(buff, str, fd, h, i);
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		str[h] = buff[i];
		i++;
		h++;
		if (!buff[i])
		{
			j = read(fd, buff, BUFFER_SIZE);
			if (j <= 0)
				return (NULL);
			str = memory_allocate(str, h);
			buff[BUFFER_SIZE] = '\0';
			i = 0;
		}
	}
	str[h] = buff[i];
	str[h + 1] = '\0';
	i++;
	return (str);
}
char	*get_next_linea(int fd)
{
	static char		*buff;
	static int		line = 0;
	char			*str;
	// int		h;
	// static int		i = 0;
	
	// h = 0;
	if (line == 0)
	{
		buff = malloc (BUFFER_SIZE + 1);
		buff[0] = '\0';
	}
	str = malloc (BUFFER_SIZE + 1);
	// while (buff[i] && buff[i] != '\n')
	// {
	// 	str[h] = buff[i];
	// 	i++;
	// 	h++;
	// }
	// if (buff[i] != '\n')
	// {
	// 	read(fd, buff, BUFFER_SIZE);
	// 	str = memory_allocate(str, h);
	// 	buff[BUFFER_SIZE] = '\0';
	// 	i = 0;
	// }
	// while (buff[i] != '\n' && buff[i])
	// {
	// 	str[h] = buff[i];
	// 	i++;
	// 	h++;
	// 	if (!buff[i])
	// 	{
	// 		read(fd, buff, BUFFER_SIZE);
	// 		str = memory_allocate(str, h);
	// 		buff[BUFFER_SIZE] = '\0';
	// 		i = 0;
	// 	}
	// }
	// str[h] = buff[i];
	// str[h + 1] = '\0';
	// i++;
	str = save_str(buff, str, fd);
	line++;
	return (str);
}

int main()
{
	int	p;

	p = open("kaixo.txt", O_RDONLY);
	printf("lehenengoa %s", get_next_linea(p));
	printf("bigarrena %s", get_next_linea(p));
	printf("hirugarrena %s", get_next_linea(p));
	printf("laugarrena %s", get_next_linea(p));
	printf("bostgarrena %s", get_next_linea(p));
	printf("seigarrena %s", get_next_linea(p));
	printf("zazpigarrena %s", get_next_linea(p));
	printf("zortzigarrena %s", get_next_linea(p));
}
 