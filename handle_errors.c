/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:59:03 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/21 17:07:36 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	base;
	int		sign;

	i = 0;
	base = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			base = base * 10 + (str[i] - 48);
		else
			ft_print_error();
		i += 1;
	}
	return (base * sign);
}

int	ft_handle_repetitions(t_list *node, int nb)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->content == nb)
			return (1);
		node = node->next;
	}
	return (0);
}
