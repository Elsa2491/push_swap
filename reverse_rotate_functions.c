/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:14:25 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/23 16:30:41 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **list)
{
	t_list	*new_node;

	new_node = ft_lstnew(0);
	ft_lstadd_front(list, new_node);
	ft_swap_first_and_last(list);
	ft_delete_last(list);
}

void	rra(t_list **lst_a)
{
	ft_reverse_rotate(lst_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst_b)
{
	ft_reverse_rotate(lst_b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_both(t_list **lst_a, t_list **lst_b, int *price_b, int *price_a)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	*price_b -= 1;
	*price_a -= 1;
	write(1, "rrr\n", 4);
}

void	ft_finish_rotation(t_list **lst, t_list *node, char lst_name)
{
	while (*lst != node)
	{
		while (lst_name == 'a')
		{
			if (*lst == node)
				break ;
			if (node->above_median)
				ra(lst);
			else
				rra(lst);
		}
		while (lst_name == 'b')
		{
			if (*lst == node)
				break ;
			if (node->above_median)
				rb(lst);
			else
				rrb(lst);
		}
	}
}
