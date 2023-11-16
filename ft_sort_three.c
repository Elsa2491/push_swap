/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:37:47 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/18 17:02:13 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list_sorted(t_list **lst)
{
	t_list	*node;

	node = *lst;
	if (!node)
		return (0);
	while (node->next != NULL)
	{
		if (node->content > node->next->content)
		{
			printf ("la liste n'est pas triée ❌\n");
			return (0);
		}
		node = node->next;
	}
	printf("la liste est triée ✅\n");
	return (1);
}


void	ft_sort_three(t_list **lst)
{
	int	max;
	int	min;

	max = ft_max2(*lst);
	min = ft_min(*lst);
	if ((*lst)->content == max)
		ft_rotate(lst);
	else if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->content == max)
		ft_reverse_rotate(lst);
	if ((*lst)->content != min)
		ft_swap_first_values(*lst);
}
