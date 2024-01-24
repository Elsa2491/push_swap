/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/24 16:09:23 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_index(t_list **lst)
{
	t_list	*node;
	int		i;

	node = *lst;
	i = 0;
	while (node)
	{
		node->index = i;
		node = node->next;
		i += 1;
	}
}

int	ft_get_target_idx(t_list **lst_a, int final_idx, int t_final_idx, int t_idx)
{
	t_list	*node;

	node = *lst_a;
	while (node)
	{
		if (node->final_index > final_idx && node->final_index < t_final_idx)
		{
			t_idx = node->index;
			t_final_idx = node->final_index;
		}
		node = node->next;
	}
	if (t_final_idx != INT_MAX)
		return (t_idx);
	node = *lst_a;
	while (node)
	{
		if (node->final_index < t_final_idx)
		{
			t_idx = node->index;
			t_final_idx = node->final_index;
		}
		node = node->next;
	}
	return (t_idx);
}

void	ft_get_target(t_list **lst_a, t_list **lst_b)
{
	t_list	*node_b;
	int		target;

	node_b = *lst_b;
	target = 0;
	while (node_b)
	{
		target = ft_get_target_idx(lst_a, node_b->final_index, INT_MAX, target);
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
		node_b->price_b = node_b->index;
		if (node_b->index > ft_find_median(*lst_b))
			node_b->price_b = (size_b - node_b->index) * -1;
		node_b->price_a = node_b->target;
		if (node_b->target > ft_find_median(*lst_a))
			node_b->price_a = (size_a - node_b->target) * -1;
		node_b = node_b->next;
	}
}

void	ft_less_move(t_list **lst_a, t_list **lst_b)
{
	t_list	*node;
	int		price_max;
	int		price_a;
	int		price_b;

	node = *lst_b;
	price_max = INT_MAX;
	while (node)
	{
		if (ft_set_pos(node->price_a) + ft_set_pos(node->price_b) < price_max)
		{
			price_max = ft_set_pos(node->price_a) + ft_set_pos(node->price_b);
			price_a = node->price_a;
			price_b = node->price_b;
		}
		node = node->next;
	}
	ft_exec(lst_a, lst_b, price_a, price_b);
}
