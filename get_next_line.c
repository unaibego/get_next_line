/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/30 12:43:28 by ubegona          ###   ########.fr       */
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
	str = malloc(h + j + 2);
	str = ft_memcpy(str, dst, h + 1);
	i++;
	free(dst);
	return (str);
}

char	*save_str(char *buff, char *str, int fd)
{
	int		h;
	static int		i = 0;
	static int j =1;
	
	h = 0;
	
	if (j <= 0) //ez badago buff-k free egin delako jarraian NULL itzultzea
	{
		free(str);
		return(NULL);
	}
	while (buff[i] && buff[i] != '\n' ) // mantendu den buff-aren amaiera str barruan sartzen duen funtzioa
	{
		str[h] = buff[i];
		i++;
		h++;
		str[h] = '\0';
		
	}
	
	if (buff[i] != '\n' && str[h] != '\0') // str baldintza hori kentzen baduzu aurreko gauza pilobat konpontzen dira, hau hasieran neukan baina orain nire logikarekin ez du ezertarako balio
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j <= 0)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[j] = '\0';
		str = memory_allocate(str, h, buff);
		i=0;
	}
	if (!buff[i]) // justo ez bada existitzen 2. funtziotik atera delako hau egin behar zaio funtzio orokorrean sartu baino lehen (FO-ean i++ egiten du !buff[i] konprobatu baino lehen)
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j <= 0)
		{
			str[h] = '\0';
			free(buff);
			return (str);
		}
		buff[j] = '\0';
		str = memory_allocate(str, h, buff);
		i = 0;
	}
	
	while (buff[i] != '\n') // hau originala da bufferra handitzen duena eta str-n sartu \n aurkitu arte
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
				return (str);
			}
			buff[j] = '\0';
			str = memory_allocate(str, h, buff);
			i = 0;
		}
	}
	str[h] = '\n';
	str[h + 1] = '\0';
	i++;
	
	
	return (str);
}
char	*get_next_line(int fd)
{
	static char		*buff;
	static int		line = 0;
	char			*str;

	if (line == 0)
	{
		buff = malloc (BUFFER_SIZE + 1);
		buff[0] = '\0';
	}
	str = malloc (BUFFER_SIZE + 1);
	str = save_str(buff, str, fd);
	line++;
	if (!str)
	{
		free(str);
		str = NULL;
	}
		
	return (str);
}

// int main()
// {
// 	int	p;

// 	p = open("variable_nls.txt", O_RDONLY);
// 	printf("lehenengoa %s", get_next_line(p));
// 	printf("bigarrena %s", get_next_line(p));
// 	printf("hirugarrena %s", get_next_line(p));
// 	printf("laugarrena %s", get_next_line(p));
// 	printf("bostgarrena %s", get_next_line(p));
// 	printf("seigarrena %s", get_next_line(p));
// 	printf("zazpigarrena %s", get_next_line(p));
// 	printf("zortzigarrena %s", get_next_line(p));
// 	printf("bederatzi %s", get_next_line(p));
// 	printf("hamar %s", get_next_line(p));
// 	printf("hamaika %s", get_next_line(p));
// 	printf("hamabi %s", get_next_line(p));
// 	printf("hamahiru %s", get_next_line(p));
// }
