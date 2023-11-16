/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/15 17:09:27 by eltouma          ###   ########.fr       */
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
	new_node->index = 0;
//	new_node->relative_to_median = 0;
	new_node->above_median = 0;		// a verif si 0 ou 1
	new_node->price = 0;
	new_node->target = NULL;
	new_node->previous = NULL;
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
	new_node->index = last_node->index + 1;
	new_node->previous = last_node;
}

void	ft_lstadd_front(t_list **list, t_list *new_node)
{
	if (!list || !new_node)
		return ;
	new_node->next = *list;
	new_node->target = NULL;
	new_node->previous = NULL;
	new_node->next->previous = new_node;
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
