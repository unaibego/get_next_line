/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/06 10:35:09 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_list
{
	char			*buff;
	char			*str;
	int				i;
	int				j;
	int				h;
}					t_list;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
t_list	ft_lstnew(char *buff, char *str, int i, int j);
#endif
