/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:33:46 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:34:50 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_specifier(char str, va_list arg)
{
	int	count;

	count = 0;
	if (str == 'd' || str == 'u' || str == 'i')
		count += ft_printint(str, arg);
	else if (str == 'x' || str == 'X')
		count += ft_printhex(str, arg);
	else if (str == 'o')
		count += ft_printoctal(arg);
	else if (str == 'c')
		count += ft_printchar(arg);
	else if (str == 'p')
		count += ft_printpointer(arg);
	else if (str == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else if (str == 's')
		count += ft_printstr(arg);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;

	if (str == NULL)
		return (-1);
	va_start(arg, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(++str) == '\0')
				return (-1);
			count += ft_print_specifier(*str, arg);
			if (*str != '\0')
				str++;
		}
		ft_putchar_fd(*str, 1);
		str++;
		count++;
	}
	va_end(arg);
	return (count);
}

