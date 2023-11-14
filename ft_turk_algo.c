/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/14 16:54:50 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_target_node(t_list *node_a, t_list *node_b)
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
			if (current_a->content > node_b->content && current_a->content < max)
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
		printf("\ntarget_node de %d est %d\n", node_b->content, node_b->target->content);
		node_b = node_b->next;
	}
	return (target_node);
}

int	ft_set_positive(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	ft_find_cheapest_cost(t_list *node_a, t_list *node_b)
{
	int		lst_a_size;
	int		lst_b_size;
	int		median_a;
	int		median_b;

	ft_set_index(node_a);
	ft_set_index(node_b);
	lst_a_size = ft_lstsize(node_a);
	lst_b_size = ft_lstsize(node_b);
	median_a = ft_find_median(node_a);
	median_b = ft_find_median(node_b);
	while (node_b)
	{
		node_b->target = ft_find_target_node(node_a, node_b);
//		printf("\ntarget_node de %d est %d\n", node_b->content, node_b->target->content);
		//node_b->b_price = node_b->index;
		node_b->price = node_b->index;
		if (node_b->index > median_b)
		{
			//	node_b->b_price = lst_b_size - node_b->index;
			node_b->price = lst_b_size - node_b->index;
			//	node_b->b_price *= -1;
		}
		if (node_b->target->index <= median_a)
			//node_b->a_price += node_b->target->index;
			node_b->price += node_b->target->index;
		else
		{
			//node_b->a_price += lst_a_size - node_b->target->index;
			node_b->price += lst_a_size - node_b->target->index;
			//	node_b->a_price *= -1;
		}
		//		node_b->total_price = ft_set_positive(node_b->a_price) + ft_set_positive(node_b->b_price);
		printf("price pour %d est %d\n", node_b->content, node_b->price);
		//		printf("cost pour %d est %d\n", node_b->content, node_b->total_price);
		node_b = node_b->next;
	}
}

void	ft_rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest_node)
{
	while (*lst_a != cheapest_node->target && *lst_b != cheapest_node)
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
	}
	ft_set_current_position(*lst_a);
	ft_set_current_position(*lst_b);
}

void	ft_reverse_rotate_both(t_list **lst_a, t_list **lst_b, t_list *cheapest_node)
{
	while (*lst_a != cheapest_node->target && *lst_b != cheapest_node)
	{
		ft_reverse_rotate(lst_a);
		ft_reverse_rotate(lst_b);
	}
	ft_set_current_position(*lst_a);
	ft_set_current_position(*lst_b);
}
