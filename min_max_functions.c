/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/11 15:09:13 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_min_node(t_list *node)
{
	int		min;
	int		tmp;
	t_list	*min_node;

	if (!node)
		return (NULL);
	tmp = 0;
	min = INT_MAX;
	min_node = NULL;
	while (node)
	{
		if (node->final_index == -1 && (!tmp || min > node->content))
		{
			min = node->content;
			min_node = node;
			tmp = 1;
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

int	ft_get_distance_from_min(t_list **lst, int min)
{
	t_list	*node;
	int		distance;

	node = *lst;
	distance = 0;
	while (node)
	{
		if (node->content == min)
			break ;
		distance += 1;
		node = node->next;
	}
	return (distance);
}
