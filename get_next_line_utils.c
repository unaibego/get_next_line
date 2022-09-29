/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:13:30 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/29 08:27:18 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	count_lines(int fd)
// {
// 	static int	line = 0;
// 	int			i;
// 	int			count;
// 	char		c;

// 	i = 0;
// 	while (i <= line)
// 	{
// 		count = 0;
// 		while (read(fd, &c, 1) && c != '\n')
// 		{
// 			printf("***zelan doa %c\n", c);
// 			count++;
// 		}
// 		i++;
// 	}
// 	line++;
// 	while (read(fd, &c, 1))
// 		;
// 	return (count);
// }
