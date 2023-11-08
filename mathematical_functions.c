/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/08 18:32:38 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_min_node(t_list *node)
{
	int	min;
	t_list	*min_node;

	if (!node)
		return (0);
	min = INT_MAX;
	while (node)
	{
		if (min > node->content)
		{
			min = node->content;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

int	ft_min(t_list *node)
{
	int	min;

	if (!node)
		return (0);
	min = node->content;
	while (node)
	{
		if (min > node->content)
			min = node->content;
		node = node->next;
	}
	return (min);
}

int	ft_max(t_list *node)
{
	int	max;

	if (!node)
		return (0);
	max = node->content;
	while (node)
	{
		if (max < node->content)
			max = node->content;
		node = node->next;
	}
	return (max);
}

t_list	*ft_find_target_node(t_list *node_a, t_list *node_b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		max;

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
	return (target_node);
}

int	ft_find_median(t_list *node)
{
	return (ft_lstsize(node) / 2);
}

void	ft_set_index(t_list *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node->index = i;
		i += 1;
		node = node->next;
	}
	printf("\n");
}

int	ft_find_cheapest_cost(t_list *node_a, t_list *node_b)
{
	int	lst_a_size;
	int	lst_b_size;
	int	median_a;
	int	median_b;
	t_list	*target;

	ft_set_index(node_a);
	ft_set_index(node_b);
	lst_a_size = ft_lstsize(node_a);
	lst_b_size = ft_lstsize(node_b);
	median_a = ft_find_median(node_a);
	median_b = ft_find_median(node_b);
	while (node_b)
	{
		target = ft_find_target_node(node_a, node_b);
		node_b->price = node_b->index;
		if (node_b->index > median_b)
			node_b->price = lst_b_size - node_b->index;
		if (target->index <= median_a)
			node_b->price += target->index;
		else
			node_b->price += lst_a_size - target->index;
		printf("cost pour %d est %d\n", node_b->content, node_b->price);
		node_b = node_b->next;
	}
}

void	ft_test(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = *lst_a;
	while (tmp)
	{
		ft_find_target_node(tmp, *lst_b);
		ft_push(lst_b, &tmp);
		tmp = tmp->next;
	}
}


