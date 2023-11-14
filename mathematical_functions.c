/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/13 15:34:38 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_min_node(t_list *node)
{
	int		min;
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
}
