/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:47:49 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/20 19:31:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_cheapest_node(t_list *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	ft_rotate_both(t_list **lst_a, t_list **lst_b)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	printf("rr\n");
}
void	ft_reverse_rotate_both(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	printf("rrr\n");
}


void	ft_move_nodes(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest_node(*lst_b);
	if (cheapest->above_median && cheapest->target->above_median)
		ft_rotate_both(lst_a, lst_b);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		ft_reverse_rotate_both(lst_a, lst_b);
	ft_finish_rotation(lst_b, cheapest, 'b');
	ft_finish_rotation(lst_a, cheapest->target, 'a');
	ft_push(lst_b, lst_a);
}
