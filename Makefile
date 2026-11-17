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
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = ft_printf.c ft_printhex.c ft_printoctal.c \
	   ft_printstr.c ft_printint.c ft_baseconvert.c \
	   ft_printchar.c ft_printpointer.c
OBJS = $(SRCS:.c=.o)

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(AR) -rcs $@ $(OBJS)
	$(AR) -rcs $@ $(LIBFT)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -f $(OBJS) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
