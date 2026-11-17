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

#include "ft_printf.h"

int	ft_printpointer(va_list arg)
{
	char			*conv;
	int				count;
	unsigned long	i;

	count = 0;
	i = 0;
	i = (uintptr_t)va_arg(arg, void *);
	conv = ft_baseconvert(i, 16, 0);
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_strlen(conv);
	ft_putnbr_fd((uintptr_t)conv, 1);
	return (count);
}
