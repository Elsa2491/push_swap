/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:37:47 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/06 15:44:09 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list_sorted(t_list **lst)
{
	t_list	*node;

	node = *lst;
	if (!node)
		return (0);
	while (node->next != NULL)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_sort_three(t_list **lst)
{
	int	max;
	int	min;

	if (!*lst)
		return ;
	max = ft_max(*lst);
	min = ft_min(*lst);
	if ((*lst)->content == max)
		ra(lst);
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content == max)
		rra(lst);
	if ((*lst)->content != min)
		sa(lst);
}

void	ft_sort_four(t_list **lst_a, t_list **lst_b)
{
	int	min;
	int	distance;

	min = ft_min(*lst_a);
	distance = ft_get_distance_from_min(lst_a, min);
	if (distance <= 2 && distance != 0)
		ra(lst_a);
	if (distance == 2)
		ra(lst_a);
	if (distance == 3)
		rra(lst_a);
	if (ft_is_list_sorted(lst_a))
		return ;
	pb(lst_a, lst_b);
	ft_sort_three(lst_a);
	pa(lst_b, lst_a);
}

void	ft_sort_five(t_list **lst_a, t_list **lst_b)
{
	int	min;
	int	distance;

	min = ft_min(*lst_a);
	distance = ft_get_distance_from_min(lst_a, min);
	if (distance <= 2 && distance != 0)
		ra(lst_a);
	if (distance == 2)
		ra(lst_a);
	if (distance == 3 || distance == 4)
		rra(lst_a);
	if (distance == 3)
		rra(lst_a);
	if (ft_is_list_sorted(lst_a))
		return ;
	pb(lst_a, lst_b);
	ft_sort_four(lst_a, lst_b);
	pa(lst_b, lst_a);
}

void	ft_little_sorting(t_list **lst_a, t_list **lst_b)
{
	int	size_a;

	size_a = ft_lstsize(*lst_a);
	if (size_a == 2)
		sa(lst_a);
	if (size_a == 3)
		ft_sort_three(lst_a);
	if (size_a == 4)
		ft_sort_four(lst_a, lst_b);
	if (size_a == 5)
		ft_sort_five(lst_a, lst_b);
}
