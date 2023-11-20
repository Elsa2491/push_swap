/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/20 17:33:49 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position_relative_to_median(t_list *node)
{
	int	i;
	int	median;

	i = 0;
	median = ft_find_median(node);
	if (!node)
		return ;
	while (node)
	{
		node->relative_to_median = i;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		i += 1;
	}
}

void	ft_find_target_node(t_list *node_a, t_list *node_b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		max;

	while (node_b)
	{
		max = INT_MAX;
		current_a = node_a;
		while (current_a)
		{
			if (current_a->content > node_b->content
				&& current_a->content < max)
			{
				max = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (node_b->content > ft_max(node_a))
			node_b->target = ft_find_min_node(node_a);
		else
			node_b->target = target_node;
		node_b = node_b->next;
	}
}

void	ft_set_price(t_list *node_a, t_list *node_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(node_a);
	size_b = ft_lstsize(node_b);
	while (node_b)
	{
		node_b->price = node_b->relative_to_median;
		if (!(node_b->above_median))
			node_b->price = size_b - (node_b->relative_to_median);
		if (node_b->target->above_median)
			node_b->price += node_b->target->relative_to_median;
		else
			node_b->price += size_a - (node_b->target->relative_to_median);
		node_b = node_b->next;
	}
}

void	ft_set_cheapest_node(t_list *node)
{
	int		cheapest;
	t_list	*cheapest_node;

	if (!node)
		return ;
	cheapest = INT_MAX;
	while (node)
	{
		if (node->price < cheapest)
		{
			cheapest = node->price;
			cheapest_node = node;
		}
		node = node->next;
	}
	cheapest_node->cheapest = 1;
}

void	ft_initialize_nodes(t_list *node_a, t_list *node_b)
{
	ft_set_position_relative_to_median(node_a);
	ft_set_position_relative_to_median(node_b);
	ft_find_target_node(node_a, node_b);
	ft_set_price(node_a, node_b);
	ft_set_cheapest_node(node_b);
}
