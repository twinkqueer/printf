/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:31:39 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 15:33:30 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(va_list arg)
{
	int		count;
	char	*s;

	s = va_arg(arg, char *);
	count = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}
