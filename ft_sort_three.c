/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:37:47 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/27 13:59:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_is_list_sorted(t_list **lst)
{
	t_list	*node;

	node = *lst;
	if (!node)
		return (0);
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_sort_three(t_list **lst)
{
	long	max;
	long	min;

	max = ft_max(*lst);
	min = ft_min(*lst);
	if ((*lst)->content == max)
		ft_rotate(lst);
	else if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->content == max)
		ft_reverse_rotate(lst);
	if ((*lst)->content != ft_min(*lst))
		ft_swap_first_values(*lst);
}
