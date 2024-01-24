/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:14:25 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/07 16:24:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_list **list)
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
	ft_printf("rra\n");
}

void	rrb(t_list **lst_b)
{
	ft_reverse_rotate(lst_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) > 1)
		ft_reverse_rotate(lst_a);
	if (ft_lstsize(*lst_b) > 1)
		ft_reverse_rotate(lst_b);
	ft_printf("rrr\n");
}

void	ft_rev_rotate_both(t_list **a, t_list **b, int *price_b, int *price_a)
{
	while (*price_a < 0 && *price_b < 0)
	{
		*price_b += 1;
		*price_a += 1;
		rrr(a, b);
	}
}
