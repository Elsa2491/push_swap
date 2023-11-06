/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:30:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/28 21:21:46 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_values(t_list *node)
{
	long	tmp;

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
		ft_lstadd_front(lst_to_push, *lst_from);
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

void	ft_push_until_three_nodes_left(t_list **lst_a, t_list **lst_b)
{
	long	size;

	size = ft_lstsize(*lst_a);
	if (size <= 3)
		ft_sort_three(lst_a);
	else
	{
		ft_push(lst_a, lst_b);
		size = ft_lstsize(*lst_a);
		while (size > 3)
		{
			if ((*lst_a)->content < ft_min(*lst_b))
				ft_reverse_rotate(lst_b);
			ft_push(lst_a, lst_b);
			size -= 1;
		}
		ft_sort_three(lst_a);
	}
}

/*void	ft_find_target_node(t_list *node_a, t_list *node_b)
{
}
*/

void	ft_find_target_node(t_list **lst_a, t_list **lst_b)
{
	int	major;
	long	median;
	t_list	*last;

	ft_push_until_three_nodes_left(lst_a, lst_b);
	while (*lst_b)
	{
		major = ft_find_major(*lst_a, *lst_b);
		median = ft_find_median(*lst_a);
		if ((*lst_b)->content > ft_max(*lst_a))
			ft_push(lst_b, lst_a);
		else if ((*lst_b)->content < major)
		{
			if (major <= median)
			{
				while ((*lst_a)->content != major)
					ft_rotate(lst_a);
			}
			else
			{
				while ((*lst_a)->content != major)
					ft_reverse_rotate(lst_a);
			}
			ft_push(lst_b, lst_a);
		}
	}
//	while (ft_lstlast(*lst_a)->content != ft_min(*lst_a))
//		ft_rotate(lst_a);
//	if (ft_lstlast(*lst_a)->content == ft_min(*lst_a))
//		ft_reverse_rotate(lst_a);
}
