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

#include "ft_printf.h"

int	ft_printhex(char type, va_list arg)
{
	char	*conversion;
	int		count;
	int		i;

	i = va_arg(arg, unsigned int);
	conversion = (char *)ft_baseconvert(i, 16, 0);
	count = ft_strlen(conversion);
	if (type == 'x')
	{
		conversion = (char *)ft_baseconvert(i, 16, 1);
		ft_putstr_fd(conversion, 1);
	}
	else if (type == 'X')
		ft_putstr_fd(conversion, 1);
	return (count);
}
