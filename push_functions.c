/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:30:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/04 22:14:08 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pb(t_list **from_a, t_list **to_b)
{
	ft_push(from_a, to_b);
	write(1, "pb\n", 3);
}

void	pa(t_list **from_b, t_list **to_a)
{
	ft_push(from_b, to_a);
	write(1, "pa\n", 3);
}

void	ft_print_list(t_list *node)
{
	while (node)
	{
		printf("%d\trank : %d\n", node->content, node->rank);
		node = node->next;
	}
}

void	ft_push_swap(t_list **lst_a, t_list **lst_b)
{
	int		size_a;

	size_a = ft_lstsize(*lst_a);
	if (size_a <= 5)
		ft_little_sorting(lst_a, lst_b);
	else
		ft_sort_more_than_five(lst_a, lst_b);
}
