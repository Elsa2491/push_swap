/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:26:29 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/05 01:14:25 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_until_five_nodes_left(t_list **lst_a, t_list **lst_b)
{
//	t_list	*node;
	int		size_a;
//	int		push;
//	int		i;

	size_a = ft_lstsize(*lst_a);
//	push = 0;
//	i = 0;
/*	while (size_a > 10 && i < size_a && push < ft_find_median(*lst_a))
	{
		node = *lst_a;
		if (node->rank <= ft_find_median(*lst_a))
		{
			pb(lst_a, lst_b);
			push += 1;
		}
		else
			ra(lst_a);
		i += 1;
		size_a -= 1;
	}*/
//	int	median = ft_find_median(*lst_a);
//	pb(lst_a, lst_b);
//	size_a -= 1;
//		node = *lst_b;
	while (size_a > 5)
	{
	//	node = *lst_b;
	/*	node = *lst_a;
		if (node->content == ft_max(*lst_a))
			ra(lst_a);
		if (node->rank <= ft_find_median(*lst_a))
		{*/
			pb(lst_a, lst_b);
	//		if (node->rank <= ft_find_median(*lst_a))
	//			rb(lst_b);
			size_a -= 1;
	//	}
	//	else
	//		ra(lst_a);
	}
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
 //	while (ft_lstsize(*lst_a) > 5)
	ft_push_until_five_nodes_left(lst_a, lst_b);
	ft_little_sorting(lst_a, lst_b); 
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
