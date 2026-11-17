/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:14:49 by mpankrat          #+#    #+#             */
/*   Updated: 2026/10/31 15:14:50 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(int argc, char *argv[])
{
	t_list *new = malloc(sizeof(t_list) * 1);
	new->content = "BLE";
	new->next = NULL;
	t_list *list = NULL;
	t_list **pointer = &list;
	ft_lstadd_front(pointer, new);
}
*/
