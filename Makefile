# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/09/23 13:05:22 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS = $(wildcard *.c)
GCC = gcc -o get_next_line.a
GCCS = gcc  -D BUFFER_SIZE=42  -c -Wall -Werror -Wextra
NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(OBJS)
	
.SILENT:

%.o: %.c
	$(GCCS) $<	
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean 
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
