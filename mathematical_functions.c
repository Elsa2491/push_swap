/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/18 16:34:50 by eltouma          ###   ########.fr       */
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

void	ft_find_target_node(t_list *node_a, t_list *node_b)
{
	t_list	*current_a;
	t_list	*target_node;
	int	max;

	while (node_b)
	{
		max = INT_MAX;
		printf("\nmax = %d\n", max);
		current_a = node_a;
		while (current_a)
		{
			if (current_a->content > node_b->content && current_a->content < max)
			{
				max = current_a->content;
				printf("\nmaintenant max = %d\n", max);
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (node_b->content > ft_max(node_a))
		{
			printf("%d > %d\n", node_b->content, ft_max(node_a));
			node_b->target = ft_find_min_node(node_a);
		}
		else
		{
			printf("%d < %d\n", node_b->content, ft_max(node_a));
			node_b->target = target_node;
		}
		printf("target_node de %d est %d\n", node_b->content, node_b->target->content); 
		node_b = node_b->next;
	}
}

int	ft_find_index(t_list *node, int index)
{
	int	count;

	count = -1;
	while (node)
	{
		if (count == index)
			return (node->content);
		count += 1;
		printf("index of %d is %d\n", node->content, count);
		node = node->next;
	}
	printf("\n");
	return (0);
}

int	ft_find_cheapest_cost(t_list *node_a, t_list *node_b)
{
	int	result;
	int	index;

	index = ft_find_index(node_b, ft_lstsize(node_b) - 1);	
//	result = ft_find_major(node_a, node_b) + index;
	result = index;
	printf("result : %d\n", result);
	return (result);
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

int	ft_find_median(t_list *node)
{
	int	result;
	int	value;

	result = ft_lstsize(node) / 2;
	value = ft_find_index(node, result);
	return (value);
}
