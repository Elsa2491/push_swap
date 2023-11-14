/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:30:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/09 18:05:55 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_values(t_list *node)
{
	int	tmp;

	if (!node || node->next == NULL)
		return ;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
}

void	ft_push(t_list **lst_from, t_list **lst_to_push)
{
	t_list	*tmp;

	if (!*lst_from)
		return ;
	tmp = (*lst_from)->next;
	if (!*lst_to_push)
	{
		*lst_to_push = *lst_from;
		(*lst_to_push)->next = NULL;
	}
	else
	{
		ft_lstadd_front(lst_to_push, *lst_from);
	}
	*lst_from = tmp;
}

void	ft_print_list(t_list *node)
{
	while (node)
	{
		printf("%d\n", node->content);
		node = node->next;
	}
}

void	ft_set_current_position(t_list *node)
{
	int	i;
	int	above_median;
	int	median;

	i = 0;
	median = ft_find_median(node);
	if (!node)
		return ;
	while (node)
	{
		node->index = i;
		if (i <= median)
			above_median = 1;
		else
			above_median = -1;
		printf("pour %d, above_median est %d\n", node->content, above_median);
		node = node->next;
		i += 1;
	}
}

void	ft_initialize_nodes(t_list *node_a, t_list *node_b)
{
	ft_set_current_position(node_a);
	ft_set_current_position(node_b);
	ft_find_target_node(node_a, node_b);
	ft_find_cheapest_cost(node_a, node_b);
}

void	ft_push_until_three_nodes_left(t_list **lst_a, t_list **lst_b)
{
	int	size;

	size = ft_lstsize(*lst_a);

	if (size == 5)
	{
		printf("La taille de la liste est de 5, déso\n");
		return ;
	}
	if (size == 3)
		ft_sort_three(lst_a);
	else
	{
		ft_push(lst_a, lst_b);
		size = ft_lstsize(*lst_a);
		while (size > 3)
		{
			ft_push(lst_a, lst_b);
			size -= 1;
		}
		ft_sort_three(lst_a);
	}
//	while (*lst_b)
//	{
		ft_initialize_nodes(*lst_a, *lst_b);
//		(*lst_b) = (*lst_b)->next;
//	}
}
