/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:26:29 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/06 19:41:11 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_until_five_nodes_left(t_list **lst_a, t_list **lst_b)
{
	int		size_a;

	size_a = ft_lstsize(*lst_a);
	if (size_a <= 5)
		ft_little_sorting(lst_a, lst_b);
	else
	{
		size_a = ft_lstsize(*lst_a);
		while (size_a > 5)
		{
			if (*lst_a < ft_find_min_node(*lst_b))
				ft_reverse_rotate(lst_b);
			pb(lst_a, lst_b);
			size_a -= 1;
		}
		ft_little_sorting(lst_a, lst_b);
	}
}

int	ft_set_lowest_position(t_list **lst)
{
	t_list	*node;
	int		position;

	node = *lst;
	position = 0;
	while (node->rank != 0)
	{
		position += 1;
		node = node->next;
	}
	return (position);
}

void	final_sort(t_list **lst_a)
{
	int	lowest;
	int	size;

	size = ft_lstsize(*lst_a);
	lowest = ft_set_lowest_position(lst_a);
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
		ft_init_position(lst_a);
		ft_init_position(lst_b);
		ft_get_target(lst_a, lst_b);
		ft_set_price(lst_a, lst_b);
		ft_less_move(lst_a, lst_b);
	}
	if (!ft_is_list_sorted(lst_a))
		final_sort(lst_a);
}
