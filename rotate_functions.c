/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/04 20:00:44 by eltouma          ###   ########.fr       */
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
	write(1, "ra\n", 3);
}

void	rb(t_list **lst_b)
{
	ft_rotate(lst_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) > 1)
		ft_rotate(lst_a);
	if (ft_lstsize(*lst_b) > 1)
		ft_rotate(lst_b);
	write(1, "rr\n", 3);
	
}

void	ft_rotate_both(t_list **lst_a, t_list **lst_b, int *price_a, int *price_b)
{
	while (*price_a > 0 && *price_b > 0)
	{
		*price_a -= 1;
		*price_b -= 1;
		rr(lst_a, lst_b);
	}
}
