/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/15 19:49:45 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_last(t_list **list)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = *list;
	while (tmp->next != NULL)
	{
		last_node = tmp;
		tmp = tmp->next;
	}
	last_node->next = NULL;
	free(tmp);
}

void	ft_delete_first(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}

void	ft_clear_list(t_list *node)
{
	t_list	*first_node;

	if (!node)
		return ;
	while (node)
	{
		first_node = node;
		node = node->next;
		free(first_node);
	}
}
