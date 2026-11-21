/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:27:21 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:24:54 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <stdint.h>
#include <stdio.h>

int	ft_printhex(char type, va_list arg)
{
	int					count;
	unsigned int		i;

	i = va_arg(arg, size_t);
	count = 0;
	if (type == 'x')
		ft_printbase(i, 16, 'x');
	else if (type == 'X')
		ft_printbase(i, 16, 'X');
	count += ft_intlen(i, 16);
	return (count);
}
