/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/09/22 21:02:00 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
