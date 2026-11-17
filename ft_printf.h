/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:32:03 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:15:34 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

typedef enum e_base
{
	LOWER_HEX = 1,
	UPPER_HEX,
	OCTAL,
	POINTER,
	BASE_10
}	t_base;
int		ft_printf(const char *, ...);
char	*ft_baseconvert(unsigned int num, int base, int upper);
int		ft_printhex(char type, va_list arg);
int		ft_printoctal(va_list arg);
int		ft_printint(char type, va_list arg);
int		ft_printstr(va_list arg);
int		ft_printchar(va_list arg);
int		ft_printpointer(va_list arg);
