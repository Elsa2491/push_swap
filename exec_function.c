/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:04:45 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/04 20:03:08 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec(t_list **lst_a, t_list **lst_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_reverse_rotate_both(lst_a, lst_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(lst_a, lst_b, &cost_a, &cost_b);
	ft_finish_rotation_a(lst_a, cost_a);
	ft_finish_rotation_b(lst_b, cost_b);
	pa(lst_b, lst_a);
}

int	ft_set_lowest_position(t_list **lst)
{
	t_list	*node;
	int	position;

	node = *lst;
	position = 0;
	while (node->rank != 0)
	{
		position += 1;
		node = node->next;
	}
	return (position);
}
