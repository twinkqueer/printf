/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:47:03 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:17:30 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printoctal(va_list arg)
{
	char	*conversion;
	int		count;
	int		i;

	i = va_arg(arg, unsigned int);
	conversion = (char *)ft_baseconvert(i, 8, 0);
	count = ft_strlen(conversion);
	ft_putstr_fd(conversion, 1);
	return (count);
}
