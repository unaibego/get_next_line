/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/05 14:15:30 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*memory_allocate(char *str, int h, char *buff)
{
	static int	i = 2;
	int			j;
	char		*dst;

	dst = malloc(h + 1);
	j = 0;
	while (buff[j] != '\n' && buff[j])
		j++;
	dst = ft_memcpy(dst, str, h + 1);
	free(str);
	str = malloc(h + j + 2);
	str = ft_memcpy(str, dst, h + 1);
	i++;
	free(dst);
	return (str);
}

t_list	ft_lstnew(char *buff, char *str, int i, int j)
{
	t_list	primerelemento;

	primerelemento.buff = buff;
	primerelemento.str = str;
	primerelemento.i = i;
	primerelemento.j = j;
	return (primerelemento);
}

t_list	save_str_final(t_list pack, int fd, int h)
{
	if (!pack.buff[pack.i])
	{
		pack.j = read(fd, pack.buff, BUFFER_SIZE);
		if (pack.j <= 0)
			return (pack.str[h] = '\0', free(pack.buff), pack.buff = 0, pack);
		pack.buff[pack.j] = '\0';
		pack.str = memory_allocate(pack.str, h, pack.buff);
		pack.i = 0;
	}
	while (pack.buff[pack.i] != '\n')
	{
		pack.str[h++] = pack.buff[pack.i++];
		if (!pack.buff[pack.i])
		{
			pack.j = read(fd, pack.buff, BUFFER_SIZE);
			if (pack.j <= 0)
				return (pack.str[h] = '\0', free(pack.buff), pack);
			pack.buff[pack.j] = '\0';
			pack.str = memory_allocate(pack.str, h, pack.buff);
			pack.i = 0;
		}
	}
	pack.str[h] = '\n';
	pack.str[h + 1] = '\0';
	return (pack);
}

char	*save_str(char *buff, char *str, int fd)
{
	static int		i = 0;
	static int		j = 1;
	t_list			pack;

	pack = ft_lstnew(buff, str, i, j);
	pack.h = 0;
	if (j <= 0)
		return (free(pack.str), pack.str = NULL, NULL);
	while (pack.buff[pack.i] && pack.buff[pack.i] != '\n' )
	{
		pack.str[pack.h++] = pack.buff[pack.i++];
		pack.str[pack.h] = '\0';
	}	
	if (pack.buff[pack.i] != '\n' && pack.str[pack.h] != '\0')
	{
		pack.j = read(fd, pack.buff, BUFFER_SIZE);
		if (pack.j <= 0)
			return (free(pack.buff), free(pack.str), j = pack.j, NULL);
		pack.buff[pack.j] = '\0';
		pack.str = memory_allocate(pack.str, pack.h, pack.buff);
		pack.i = 0;
	}
	pack = save_str_final(pack, fd, pack.h);
	return (j = pack.j, i = pack.i + 1, pack.str);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	static int		line = 0;
	char			*str;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	if (line == 0)
	{
		buff = malloc (BUFFER_SIZE + 1);
		buff[0] = '\0';
	}
	str = malloc (BUFFER_SIZE + 1);
	str = save_str(buff, str, fd);
	// printf("nire str %d", str[0]);
	line++;
	// if (!str)
	// {
	// 	free(str);
	// 	str = NULL;
	// }
	return (str);
}

// int main(void)
// {
// 	int	p;

// 	p = open("empty", O_RDONLY);
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
