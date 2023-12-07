/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:26:55 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/07 16:27:40 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_values(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !((*lst)->next))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	ft_swap_first_and_last(t_list **list)
{
	t_list	*last;
	t_list	*tmp;

	tmp = *list;
	last = *list;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = *list;
	last->next = (*list)->next;
	(*list)->next = NULL;
	*list = last;
}

void	sa(t_list **lst)
{
	ft_swap_first_values(lst);
	ft_printf("sa\n");
}
