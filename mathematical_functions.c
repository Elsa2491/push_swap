/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematical_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/24 14:23:15 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_handle_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

void	ft_handle_sign_repetition(char **tab, int j)
{
	if (tab)
	{
		while (tab[j])
			free(tab[j++]);
		free(tab);
		tab = NULL;
	}
}*/

int	ft_find_median(t_list *node)
{
	return (ft_lstsize(node) / 2);
}

int	ft_set_pos(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}
