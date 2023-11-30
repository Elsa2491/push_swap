/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/27 19:18:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_median(t_list *node)
{
//	printf("median = %d\n", ft_lstsize(node) / 2);
	return (ft_lstsize(node) / 2);
}

int	ft_set_pos(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}
