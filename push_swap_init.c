/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/30 17:21:12 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_position(t_list **lst)
{
	t_list	*node;
	int		i;

	node = *lst;
	i = 0;
	while (node)
	{
		node->position = i;
		node = node->next;
		i += 1;
	}
}

int	ft_get_target_pos(t_list **lst_a, int rank, int target_rank, int target_pos)
{
	t_list	*node;

	node = *lst_a;
	while (node)
	{
		if (node->rank > rank && node->rank < target_rank)
		{
			target_pos = node->position;
			target_rank = node->rank;
		}
		node = node->next;
	}
	if (target_rank != ft_max(*lst_a)) // target_rank != INT_MAX?
		return (target_pos);
	node = *lst_a;
	while (node)
	{
		if (node->rank < target_rank)
		{
			target_pos = node->position;
			target_rank = node->rank;
		}
		node = node->next;
	}

	return (target_pos);
}

void	ft_get_target(t_list **lst_a, t_list **lst_b)
{
	t_list	*node_b;
	int		target;

	node_b = *lst_b;
	target = 0;
	while (node_b)
	{
		target = ft_get_target_pos(lst_a, node_b->rank, ft_max(*lst_a), target); // ou INT_MAX
		node_b->target = target;
		node_b = node_b->next;
	}	
}

void	ft_set_price(t_list **lst_a, t_list **lst_b)
{
	t_list	*node_b;
	int		size_a;
	int		size_b;

	node_b = *lst_b;
	size_a = ft_lstsize(*lst_a);
	size_b = ft_lstsize(*lst_b);
	while (node_b)
	{
		node_b->price_b = node_b->position;
		if (node_b->position > ft_find_median(*lst_b))
			node_b->price_b = (size_b - node_b->position) * -1;
		node_b->price_a = node_b->target;
		if (node_b->target > ft_find_median(*lst_a))
			node_b->price_a = (size_a - node_b->target) * -1;
		node_b = node_b->next;
	}
}

void	ft_less_move(t_list **lst_a, t_list **lst_b)
{
	t_list	*node_b;
	int		price_max;
	int		price_a;
	int		price_b;

	node_b = *lst_b;
	price_max = INT_MAX;
	while (node_b)
	{
		if (ft_set_pos(node_b->price_a) + ft_set_pos(node_b->price_b) < price_max)
		{
			price_max = ft_set_pos(node_b->price_a) + ft_set_pos(node_b->price_b);
			price_a = node_b->price_a;
			price_b = node_b->price_b;
		}
		node_b = node_b->next;
	}
	ft_exec(lst_a, lst_b, price_a, price_b);
}
