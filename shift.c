/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:47:49 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/28 19:07:53 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
/*
void	ft_move_nodes(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest_node(*lst_b);
//	printf("1price b : %d\n", cheapest->price_b);
//	printf("1price a : %d\n", cheapest->price_a);
	if (cheapest->above_median && cheapest->target->above_median && (cheapest->price_b > 0 && cheapest->price_a > 0))
		ft_rotate_both(lst_a, lst_b, &(cheapest->price_b), &(cheapest->price_a));
	if (!(cheapest->above_median) && !(cheapest->target->above_median) && (cheapest->price_b > 0 && cheapest->price_a > 0))
		ft_reverse_rotate_both(lst_a, lst_b, &(cheapest->price_b), &(cheapest->price_a));
//	printf("2price b : %d\n", cheapest->price_b);
//	printf("2price a : %d\n", cheapest->price_a);
	if ((cheapest->price_b > 0 && cheapest->price_a == 0))
		ft_finish_rotation(lst_b, cheapest, 'b');
	if ((cheapest->price_b == 0 && cheapest->price_a > 0))
		ft_finish_rotation(lst_a, cheapest->target, 'a');
//	printf("3price b : %d\n", cheapest->price_b);
//	printf("3price a : %d\n", cheapest->price_a);
	pa(lst_b, lst_a);
}*/
