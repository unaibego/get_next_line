/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/27 08:36:48 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char		*buff;
// 	int				i;
// 	static int		line = 0;
// 	int				j;
// 	int				h;
// 	char			*str;
// 	// static int      entro = 0 ;

// 	j = 0;
// 	if (line == 0)
// 	{
// 		buff = malloc (BUFFER_SIZE);
// 		j = read(fd, buff, BUFFER_SIZE);
// 	}
// 		// buff = malloc (BUFFER_SIZE);
// 		// j = read(fd, buff, BUFFER_SIZE);
// 	str = malloc (j + 100);
// 	j = 0;
// 	i = 0;
// 	while (j <= line)
// 	{
// 		h = 0; 
// 		// printf( " baldintza==|%c| i==|%d|    buff==|%s|\n",buff[i], i, buff);
// 		while (buff[i] != '\n' && buff[i])
// 		{
// 			str[h] = buff[i];
// 			i++;
// 			h++;
// 			if (!buff[i] && read(fd, buff, BUFFER_SIZE))
// 			{
// 				i = 0;
// 			}
// 			// printf("  j==|%d|    buff==|%s|\n", j, buff);
// 			// printf("     j==|%d|   line==|%d|    str==|%s|   buff==|%s|   \n", j, line, str, buff);
// 		}
// 		str[h] = buff[i];
// 		str[h + 1] = '\0';
// 		i++;
// 		j++;
// 		if (j == 1)
// 		{
// 			if (!buff[i] && read(fd, buff, BUFFER_SIZE))
// 			{
// 				i = 0;
// 			}
// 		}
		
// 		// printf("*%d   *******************************************\n", line);
// 		// printf("******************hau da j %d eta hau zelan doa str %s eta buff %d\n", j, str, buff[i]=='\n');
// 	}
// 	line = 1;
// 	return (str);
// }

// int main()
// {
// 	int	p;

// 	p = open("kaixo.txt", O_RDONLY);
// 	printf("lehenengoa %s\n", get_next_line(p));
// 	printf("bigarrena %s\n", get_next_line(p));
// 	printf("hirugarrena %s\n", get_next_line(p));
// 	printf("laugarrena %s\n", get_next_line(p));
// 	printf("bostgarrena %s\n", get_next_line(p));
// 	printf("seigarrena %s\n", get_next_line(p));
// 	printf("zazpigarrena %s\n", get_next_line(p));


// }
 