/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:30:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/15 14:27:56 by eltouma          ###   ########.fr       */
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

void	ft_push_swap(t_list **lst_a, t_list **lst_b)
{
//	t_list	*smallest;
	int		size_a;

	size_a = ft_lstsize(*lst_a);
	if (size_a == 5)
		ft_sort_five(lst_a, lst_b);
	else
	{
		while (size_a > 3)
		{
			ft_push(lst_a, lst_b);
			size_a -= 1;
		}
	}
		ft_sort_three(lst_a);
}
