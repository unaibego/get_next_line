/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/29 12:31:33 by ubegona          ###   ########.fr       */
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

char	*memory_allocate(char *str, int h, char *buff)
{
	static int i = 2;
	int j;
	char 	*dst;
	
	dst = malloc(h + 1);
	j = 0;
	// printf( " buff==|%s|", buff);
	while (buff[j] != '\n' && buff[j])
		j++;
	// printf(" j==|%d|\n", j);
	dst = ft_memcpy(dst, str, h + 1);
	free(str);
	str = NULL;
	str = malloc(h + j + 2);
	str = ft_memcpy(str, dst, h + 1);
	i++;
	return (str);
}
int	newline(char *buff, char *str, int fd, int h, int i)
{
	int j;
	
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
				return (- 1);
			str = memory_allocate(str, h, buff);
			buff[BUFFER_SIZE] = '\0';
			i = 0;
		}
	}
	str[h] = buff[i];
	str[h + 1] = '\0';
	return (i);
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
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[j] = '\0';
		str = memory_allocate(str, h, buff);
		
		
	}
	i=0;
	while (buff[i] != '\n')
	{
		str[h] = buff[i];
		
		i++;
		h++;
		if (!buff[i])
		{
			j = read(fd, buff, BUFFER_SIZE);
			if (j <= 0)
			{
				str[h] = '\0';
				free(buff);
				buff = NULL;
				// str[h + 1] = '\0';
				// printf("  buff==|%s|   str=|%s|\n", buff, str);
				return (str);
			}
			buff[j] = '\0';
			str = memory_allocate(str, h, buff);
			i = 0;
		}
		
	}
	str[h] = buff[i];
	str[h + 1] = '\0';
	
	// i = newline(buff, str, fd, h, i);
	// printf("%s\n",str);
	// if (i == -1)
	// 	return(NULL);
	i++;
	return (str);
}
char	*get_next_line(int fd)
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
	// 	printf("agur");

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
	// 	printf("%s", );

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

	p = open("1char.txt", O_RDONLY);
	printf("lehenengoa %s", get_next_line(p));
	printf("bigarrena %s", get_next_line(p));
	printf("hirugarrena %s", get_next_line(p));
	printf("laugarrena %s", get_next_line(p));
	printf("bostgarrena %s", get_next_line(p));
	printf("seigarrena %s", get_next_line(p));
	printf("zazpigarrena %s", get_next_line(p));
	printf("zortzigarrena %s", get_next_line(p));
}
