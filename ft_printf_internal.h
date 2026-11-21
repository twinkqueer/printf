/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:57:21 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/21 13:57:22 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
void	ft_putnbr_fd(long num, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_printhex(char type, va_list arg);
int		ft_printoctal(va_list arg);
int		ft_printint(char type, va_list arg);
int		ft_printstr(va_list arg);
int		ft_printchar(va_list arg);
int		ft_printpointer(va_list arg);
int		ft_printbase(size_t n, unsigned int b, char format);
int		ft_intlen(size_t nbr, uint8_t base);

#endif
