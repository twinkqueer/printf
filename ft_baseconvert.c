/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseconvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:39:50 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/03 14:40:30 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_baseconvert(unsigned int num, int base, int upper)
{
	static char		*representation;
	static char		buffer[50];
	char			*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	representation = "0123456789ABCDEF";
	while (num != 0)
	{
		if (upper == 0)
			representation = "0123456789abcdef";
		*--ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}
