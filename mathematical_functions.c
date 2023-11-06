/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:29:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/28 21:20:19 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_min(t_list *node)
{
	long	min;

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

long	ft_max(t_list *node)
{
	long	max;

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

int	ft_find_major(t_list *node_a, t_list *node_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	majorant;

	while (node_b)
	{
		majorant = ft_max(node_b);
		current_a = node_a;
		while (current_a)
		{
			if (current_a->content > node_b->content
				&& current_a->content < majorant)
			{
				majorant = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (majorant == 2147483647)
			node_b->target->content = ft_min(node_a);
		else
		{
			node_b->target = target_node;
			printf("majorant de %d est %d\n", node_b->content, target_node->content);
		}
		node_b = node_b->next;
	}
	return (target_node->content);
}

/*long	ft_find_major(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	long	majorant;

	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->content > (*lst_b)->content)
		{
			majorant = tmp->content;
			while (tmp->next != NULL)
			{
				if (tmp->next->content > (*lst_b)->content
					&& tmp->next->content < majorant)
					majorant = tmp->next->content;
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (majorant);
}*/

long	ft_find_index(t_list *node, long index)
{
	long	count;

	count = 0;
	while (node)
	{
		if (count == index)
			return (node->content);
		count += 1;
		node = node->next;
	}
}
/*
long	ft_find_median(t_list *node)
{
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*previous;
	long	result;
	long	value;


	ptr1 = node;
	ptr2 = node;
	previous = node;
	if (node != NULL)
	{
		while (ptr2 != NULL && ptr2->next != NULL)
		{
			ptr2 = ptr2->next->next;
			previous = ptr1;
			ptr1 = ptr1->next;
		}
		if (ptr2 != NULL)
			result = ptr1->content;
		else
			result = (ptr1->content + previous->content) / 2;
	}
//	result = (ft_lstsize(node) + 1) / 2;
	value = ft_find_index(node, result);
	return (result);
}
*/

long	ft_find_median(t_list *node)
{
	long	result;
	long	value;

	result = ft_lstsize(node) / 2;
	value = ft_find_index(node, result);
	return (value);
}
