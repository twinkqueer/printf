/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:12:15 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:15:05 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(char type, va_list arg)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	if (type == 'u')
	{
		i = va_arg(arg, unsigned int);
		ft_putnbr_fd(i, 1);
		count += ft_strlen(ft_itoa(i));
	}
	else
	{
		i = va_arg(arg, int);
		ft_putnbr_fd(i, 1);
		count += ft_strlen(ft_itoa(i));
	}
	return (count);
}
