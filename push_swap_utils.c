/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/06 15:48:12 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->rank = -1;
	new_node->price_a = 0;
	new_node->price_b = 0;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_lstadd_back(t_list **list, int nb)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list)
		return ;
	last_node = ft_lstlast(*list);
	new_node = ft_lstnew(nb);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
}

void	ft_lstadd_front(t_list **list, t_list *new_node)
{
	if (!list || !new_node)
		return ;
	new_node->next = *list;
	*list = new_node;
}

int	ft_lstsize(t_list *node)
{
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node)
	{
		i += 1;
		node = node->next;
	}
	return (i);
}
