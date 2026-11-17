/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:16:45 by mpankrat          #+#    #+#             */
/*   Updated: 2026/10/31 15:16:45 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*a++ != *b++)
		{
			return (((int)a[-1]) - ((int)b[-1]));
		}
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s[] = "abcj";
	char s2[] = "abce";
	printf("%d", ft_memcmp(s, s2, 4));
	printf("%d", memcmp(s, s2, 4));
}
*/
