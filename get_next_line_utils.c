/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:13:30 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/06 10:33:44 by ubegona          ###   ########.fr       */
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

t_list	ft_lstnew(char *buff, char *str, int i, int j)
{
	t_list	primerelemento;

	primerelemento.buff = buff;
	primerelemento.str = str;
	primerelemento.i = i;
	primerelemento.j = j;
	return (primerelemento);
}