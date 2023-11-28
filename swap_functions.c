/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:26:55 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/25 19:13:15 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_values(t_list *node)
{
	int	tmp;

	if (!node || node->next == NULL)
		return ;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
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

void	sa(t_list *node)
{
	ft_swap_first_values(node);
	write(1, "sa\n", 3);
}
