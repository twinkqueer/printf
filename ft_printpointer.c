/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:11:02 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/05 18:14:31 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printpointer(va_list arg)
{
	int				count;
	uintptr_t		i;

	count = 0;
	i = (uintptr_t)va_arg(arg, void *);
	if (i == 0)
	{
		count += 5;
		ft_putstr_fd("(nil)", 1);
		return (count);
	}
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_printbase(i, 16, 'x');
	return (count);
}
