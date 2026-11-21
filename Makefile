# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 17:46:18 by mpankrat          #+#    #+#              #
#    Updated: 2026/11/02 17:47:59 by mpankrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printhex.c  \
	   ft_printstr.c ft_printint.c ft_printbase.c \
	   ft_printchar.c ft_printpointer.c

OBJS = $(SRCS:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean 
	$(MAKE)	$(NAME)

.PHONY: all clean fclean re
