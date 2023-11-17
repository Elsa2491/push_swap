/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/17 18:36:12 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_and_last(t_list **list)
{
	t_list	*avant_dernier;
	t_list	*deuxieme;
	t_list	*tmp;

	tmp = ft_lstlast(*list);
	avant_dernier = tmp->previous;
	deuxieme = (*list)->next;

	(*list)->next = NULL;
	tmp->previous = NULL;

	(*list)->previous = avant_dernier;
	tmp->next = deuxieme;

	avant_dernier->next = *list;
	deuxieme->previous = tmp;

	tmp = avant_dernier->next;
	(*list) = deuxieme->next;
	
//	tmp = (*list)->content;
//	(*list)->content = last_node->content;
//	last_node->content = tmp;
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*new_node;

	new_node = ft_lstnew(0);
	ft_lstadd_front(list, new_node);
	ft_swap_first_and_last(list);
	ft_delete_last(list);
}

void	ft_rotate(t_list **list)
{
	ft_lstadd_back(list, 0);
	ft_swap_first_and_last(list);
	ft_delete_first(list);
}

void	ft_finish_rotation(t_list **lst, t_list *node, char lst_name)
{
	while (*lst != node)
	{
		if (lst_name == 'a')
		{
			if (node->above_median)
				ft_rotate(lst);
			else
				ft_reverse_rotate(lst);
		}
		else if (lst_name == 'b')
		{
			if (node->above_median)
				ft_rotate(lst);
			else
				ft_reverse_rotate(lst);
		}
	}
}
