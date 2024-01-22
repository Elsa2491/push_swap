/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/07 16:26:18 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **list)
{
	if (!*list)
		return ;
	ft_lstadd_back(list, 0);
	ft_swap_first_and_last(list);
	ft_delete_first(list);
}

void	ra(t_list **lst_a)
{
	if (!*lst_a)
		return ;
	ft_rotate(lst_a);
	ft_printf("ra\n");
}

void	rb(t_list **lst_b)
{
	ft_rotate(lst_b);
	ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) > 1)
		ft_rotate(lst_a);
	if (ft_lstsize(*lst_b) > 1)
		ft_rotate(lst_b);
	ft_printf("rr\n");
}

void	ft_rotate_both(t_list **a, t_list **b, int *price_a, int *price_b)
{
	while (*price_a > 0 && *price_b > 0)
	{
		*price_a -= 1;
		*price_b -= 1;
		rr(a, b);
	}
}
