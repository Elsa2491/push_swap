/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:04:45 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/06 19:41:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finish_rotation_a(t_list **lst, int price)
{
	while (price)
	{
		if (price > 0)
		{
			ra(lst);
			price -= 1;
		}
		else
		{
			rra(lst);
			price += 1;
		}
	}
}

void	ft_finish_rotation_b(t_list **lst, int price)
{
	while (price)
	{
		if (price > 0)
		{
			rb(lst);
			price -= 1;
		}
		else
		{
			rrb(lst);
			price += 1;
		}
	}
}

void	ft_exec(t_list **lst_a, t_list **lst_b, int cost_a, int cost_b)
{
	ft_rev_rotate_both(lst_a, lst_b, &cost_a, &cost_b);
	ft_rotate_both(lst_a, lst_b, &cost_a, &cost_b);
	ft_finish_rotation_a(lst_a, cost_a);
	ft_finish_rotation_b(lst_b, cost_b);
	pa(lst_b, lst_a);
}
