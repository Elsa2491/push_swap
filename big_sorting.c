/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:26:29 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/19 15:41:39 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_until_five_nodes_left(t_list **lst_a, t_list **lst_b)
{
	int		size_a;

	size_a = ft_lstsize(*lst_a);
	while (size_a > 5)
	{
		if (*lst_a < ft_find_min_node(*lst_b))
			rrb(lst_b);
		pb(lst_a, lst_b);
		size_a -= 1;
	}
	ft_little_sorting(lst_a, lst_b);
}

static int	ft_set_lowest_index(t_list **lst)
{
	t_list	*node;
	int		index;

	node = *lst;
	index = 0;
	while (node->final_index != 0)
	{
		index += 1;
		node = node->next;
	}
	return (index);
}

static void	final_sort(t_list **lst_a)
{
	int	lowest;
	int	size;

	size = ft_lstsize(*lst_a);
	lowest = ft_set_lowest_index(lst_a);
	if (lowest > ft_find_median(*lst_a))
	{
		while (lowest < size)
		{
			rra(lst_a);
			lowest += 1;
		}
	}
	else
	{
		while (lowest > 0)
		{
			ra(lst_a);
			lowest -= 1;
		}
	}
}

void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b)
{
	ft_push_until_five_nodes_left(lst_a, lst_b);
	while (*lst_b)
	{
		ft_init_index(lst_a);
		ft_init_index(lst_b);
		ft_get_target(lst_a, lst_b);
		ft_set_price(lst_a, lst_b);
		ft_less_move(lst_a, lst_b);
	}
	if (!ft_is_list_sorted(lst_a))
		final_sort(lst_a);
}
