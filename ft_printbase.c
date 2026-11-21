/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 02:52:06 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/21 02:52:07 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_baselen(unsigned long n, unsigned int b)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= b;
		len++;
	}
	return (len);
}

int	ft_printbase(size_t n, unsigned int b, char format)
{
	char	*base;
	int		len;

	len = ft_baselen(n, b);
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= b)
		ft_printbase(n / b, b, format);
	ft_putchar_fd(base[n % b], 1);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>
int main(int argc, char *argv[])
{
	int a = ft_printbase(INT_MAX, 16, 'x');
	printf("%d", a);
	return a;
}
*/
