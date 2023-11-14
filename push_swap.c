/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:30:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/09 18:05:55 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_first_values(t_list *node)
{
	int	tmp;

	if (!node || node->next == NULL)
		return ;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
}

void	ft_push(t_list **lst_from, t_list **lst_to_push)
{
	t_list	*tmp;

	if (!*lst_from)
		return ;
	tmp = (*lst_from)->next;
	if (!*lst_to_push)
	{
		*lst_to_push = *lst_from;
		(*lst_to_push)->next = NULL;
	}
	else
	{
		ft_lstadd_front(lst_to_push, *lst_from);
	}
	*lst_from = tmp;
}

void	ft_print_list(t_list *node)
{
	while (node)
	{
		printf("%d\n", node->content);
		node = node->next;
	}
}

void	ft_set_current_position(t_list *node)
{
	int	i;
//	int	above_median;
	int	median;

	i = 0;
	median = ft_find_median(node);
	if (!node)
		return ;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
//		printf("pour %d, above_median est %d\n", node->content, above_median);
		node = node->next;
		i += 1;
	}
}

void	ft_initialize_nodes(t_list *node_a, t_list *node_b)
{
	ft_set_current_position(node_a);
	ft_set_current_position(node_b);
	ft_find_target_node(node_a, node_b);
	ft_find_cheapest_cost(node_a, node_b);
	ft_find_min_price(node_b);
}

void	finish_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->index < ft_find_median(*stack))
				ft_rotate(stack);
			else
				ft_reverse_rotate(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->index < ft_find_median(*stack))
				ft_rotate(stack);
			else
				ft_reverse_rotate(stack);
		}
	}
}

t_list	*ft_return_cheapest(t_list *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->price)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_move_nodes(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest_node;

	cheapest_node = ft_return_cheapest(*lst_b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
	{
		printf("cheapest_node->above_median 😍 == %d\n", cheapest_node->above_median);
		printf("cheapest_node->above_median 😍 == %d\n", cheapest_node->target->above_median);
		ft_rotate_both(lst_a, lst_b, cheapest_node);
	}
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
	{
		printf("COUCOU PETITE PERRUCHE\n");
		printf("!cheapest_node->above_median 🫧 == %d\n", !(cheapest_node->above_median));
		printf("!cheapest_node->target->above_median 🫧 == %d\n", !(cheapest_node->target->above_median));
		ft_reverse_rotate_both(lst_a, lst_b, cheapest_node);
	}
/*	else if (!(cheapest_node->above_median) || !(cheapest_node->target->above_median))
	{
		printf("COUCOU PETITE PERRUCHE\n");
		printf("!cheapest_node->above_median *️⃣ == %d\n", !(cheapest_node->above_median));
		printf("!cheapest_node->target->above_median *️⃣ == %d\n", !(cheapest_node->target->above_median));
//		ft_rotate(lst_b);
//		ft_reverse_rotate_both(lst_a, lst_b, cheapest_node);
		ft_reverse_rotate(lst_a);
	}*/
	finish_rotation(lst_b, cheapest_node, 'b');
	finish_rotation(lst_a, cheapest_node->target, 'a');
	ft_push(lst_b, lst_a);
}
void	ft_push_until_three_nodes_left(t_list **lst_a, t_list **lst_b)
{
	int	size;
	t_list	*smallest;

	size = ft_lstsize(*lst_a);
	if (size == 5)
	{
		printf("La taille de la liste est de 5, déso\n");
		return ;
	}
	if (size == 3)
		ft_sort_three(lst_a);
	else
	{
		ft_push(lst_a, lst_b);
		size = ft_lstsize(*lst_a);
		while (size > 3)
		{
		//	if ((*lst_a)->content == ft_max(*lst_a))
		//		ft_rotate(lst_a);
			ft_push(lst_a, lst_b);
			size -= 1;
		}
		ft_sort_three(lst_a);
	}
	while (*lst_b)
	{
		ft_initialize_nodes(*lst_a, *lst_b);
	//	ft_move_nodes(lst_a, lst_b);
		*lst_b = (*lst_b)->next;
	}
	ft_set_current_position(*lst_a);
	smallest = ft_find_min_node(*lst_a);
	if (smallest->above_median)
		while (*lst_a != smallest)
			ft_rotate(lst_a);
	else
		while (*lst_a != smallest)
			ft_reverse_rotate(lst_a);
}
