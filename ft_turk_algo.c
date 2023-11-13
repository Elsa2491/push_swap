/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:22 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/13 18:43:37 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_target_node(t_list *node_a, t_list *node_b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		max;

	max = INT_MAX;
	current_a = node_a;
	while (current_a)
	{
		if (current_a->content > node_b->content && current_a->content < max)
		{
			max = current_a->content;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	return (target_node);
}

int	ft_set_positive(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	ft_find_cheapest_cost(t_list *node_a, t_list *node_b)
{
	int		lst_a_size;
	int		lst_b_size;
	int		median_a;
	int		median_b;
	t_list	*target;

	ft_set_index(node_a);
	ft_set_index(node_b);
	lst_a_size = ft_lstsize(node_a);
	lst_b_size = ft_lstsize(node_b);
	median_a = ft_find_median(node_a);
	median_b = ft_find_median(node_b);
	while (node_b)
	{
		target = ft_find_target_node(node_a, node_b);
//		printf("\ntarget_node de %d est %d\n", node_b->content, target->content);
		node_b->b_price = node_b->index;
		if (node_b->index > median_b)
		{
			node_b->b_price = lst_b_size - node_b->index;
			node_b->b_price *= -1;
		}
		if (target->index <= median_a)
			node_b->a_price += target->index;
		else
		{
			node_b->a_price += lst_a_size - target->index;
			node_b->a_price *= -1;
		}
		node_b->total_price = ft_set_positive(node_b->a_price) + ft_set_positive(node_b->b_price);
		printf("cost pour b %d est %d\n", node_b->content, node_b->b_price);
		printf("cost pour %d est %d\n", node_b->content, node_b->total_price);
		node_b = node_b->next;
	}
}

void	ft_rotate_both(t_list ** lst_a, t_list **lst_b)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
}

void	ft_reverse_rotate_both(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
}

// void	ft_test(t_list **node_a, t_list **node_b)
// {
// 	t_list	*tmp;
// 	t_list *a;
// 	t_list *b;
// 	int		median_a;
// 	int		median_b;
// 	t_list	*target;

// 	a = *node_a;
// 	b =*node_b;
// 	median_a = ft_find_median(a);
// 	median_b = ft_find_median(b);
// 	printf("a|%d| b|%d|\n", a->content, b->content);

// 	while (b)
// 	{
// 		target = ft_find_target_node(node_a, node_b);
// 		ft_find_cheapest_cost(a, b);
// 		tmp = ft_find_min_cost(b);
// 		printf("bonjour antoine : b|%d| a|%d| t|%d|\n", tmp->b_price, tmp->a_price, tmp->total_price);
// 		while ((tmp->b_price > 0 && tmp->index < median_b) && (tmp->a_price > 0 && target->index < median_a))
// 		{
// 			ft_rotate_both(&a, &b);
// 			tmp->b_price -= 1;
// 			tmp->a_price -= 1;
// 		}
// 		printf("a\n");
// 		while ((tmp->b_price < 0 && tmp->index > median_b) && (tmp->a_price < 0 && target->index > median_a))
// 		///while (tmp->b_price < 0 && tmp->a_price < 0)
// 		{
// 			ft_reverse_rotate_both(&a, &b);	
// 			tmp->b_price += 1;
// 			tmp->a_price += 1;
// 		}
// 		printf("b\n");
// 		while ((tmp->b_price > 0 && tmp->index < median_b))
// 	//	while (tmp->b_price > 0)
// 		{
// 			ft_rotate(&b);
// 			tmp->b_price -= 1;
// 		}
// 		printf("c\n");
// 		while ((tmp->a_price > 0 && tmp->index < median_a))
// //		while (tmp->a_price > 0)
// 		{
// 			ft_rotate(&a);	
// 			tmp->a_price -= 1;
// 		}
// 		printf("d\n");
// 		while ((tmp->b_price < 0 && tmp->index > median_b))
// //		while (tmp->b_price < 0)
// 		{
// 			ft_reverse_rotate(&b);	
// 			tmp->b_price += 1;
// 		}
// 		printf("e\n");
// 		while ((tmp->a_price < 0 && tmp->index > median_a))
// 		///while (tmp->a_price < 0)
// 		{
// 			printf("coucou petite perruche\n");
// 			ft_reverse_rotate(&a);
// 			printf("c'est un elan qui a 2/3 ans\n");
// 			tmp->a_price += 1;
// 		}
// 		printf("COUCOU\n");
// 		ft_push(&b, &a);
// 		(printf("-6-\nA :\n"), ft_print_list(a), ((b) ? printf("\nB :\n"), ft_print_list(b) : printf("b est vide\n\n")), printf("\n"));
// 	}
// }

void	ft_birdnest2(t_list **node_a, t_list **node_b, t_list **tmp);

void	ft_birdnest(t_list **node_a, t_list **node_b)
{
	t_list	*tmp;
	int		median_a;
	int		median_b;
	t_list	*target;

	median_a = ft_find_median(*node_a);
	median_b = ft_find_median(*node_b);

	while (*node_b)
	{
		target = ft_find_target_node(*node_a, *node_b);
		ft_find_cheapest_cost(*node_a, *node_b);
		tmp = ft_find_min_cost(*node_b);
		printf("bonjour antoine : b|%d| a|%d| t|%d|\n", tmp->b_price, tmp->a_price, tmp->total_price);
		ft_birdnest2(node_a, node_b, &tmp);
	}
}

void	ft_birdnest2(t_list **a, t_list **b, t_list **tmp)
{
	while ((*tmp)->b_price > 0 && (*tmp)->a_price > 0)
		{
			ft_rotate_both(a, b);
			(*tmp)->b_price -= 1;
			(*tmp)->a_price -= 1;
		}
		printf("a\n");
		while ((*tmp)->b_price < 0 && (*tmp)->a_price < 0)
		///while ((*tmp)->b_price < 0 && (*tmp)->a_price < 0)
		{
			ft_reverse_rotate_both(a, b);	
			(*tmp)->b_price += 1;
			(*tmp)->a_price += 1;
		}
		printf("b\n");
		while ((*tmp)->b_price > 0)
	//	while ((*tmp)->b_price > 0)
		{
			ft_rotate(b);
			(*tmp)->b_price -= 1;
		}
		printf("c\n");
		while ((*tmp)->a_price > 0)
//		while ((*tmp)->a_price > 0)
		{
			ft_rotate(a);	
			(*tmp)->a_price -= 1;
		}
		printf("d\n");
		while ((*tmp)->b_price < 0) 
//		while ((*tmp)->b_price < 0)
		{
			ft_reverse_rotate(b);	
			(*tmp)->b_price += 1;
		}
		printf("e\n");
		while ((*tmp)->b_price < 0)
		///while ((*tmp)->a_price < 0)
		{
			printf("coucou petite perruche\n");
			ft_reverse_rotate(a);
			printf("c'est un elan qui a 2/3 ans\n");
			(*tmp)->a_price += 1;
		}
		printf("COUCOU\n");
		ft_push(b, a);
		(printf("-6-\nA :\n"), ft_print_list(*a), ((*b) ? printf("\nB :\n"), ft_print_list(*b) : printf("b est vide\n\n")), printf("\n"));
//	}
}