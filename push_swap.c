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
	t_list	*head_from;
	t_list	*head_to;

	if (!*lst_from)
		return ;
	head_to = *lst_to_push;
	head_from = *lst_from;
	tmp = *lst_from;
	*lst_from = head_from->next; 
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*lst_to_push = head_to;
	}
	else
	{
		tmp->next = head_to;
		*lst_to_push = tmp;
	}
	//*lst_from = tmp;
}

void	ft_print_list(t_list *node)
{
	while (node)
	{
		printf("%d\n", node->content);
		node = node->next;
	}
}

void	ft_push_until_three_nodes_left(t_list **lst_a, t_list **lst_b)
{
	long	size;

	size = ft_lstsize(*lst_a);
	if (size == 3)
		ft_sort_three(lst_a);
	else
	{
		ft_push(lst_a, lst_b);
		size = ft_lstsize(*lst_a);
		while (size > 3)
		{
			if ((*lst_a)->content == ft_max(*lst_a))
				ft_rotate(lst_a);
			ft_push(lst_a, lst_b);
			size -= 1;
		}
		ft_sort_three(lst_a);
	}
}
