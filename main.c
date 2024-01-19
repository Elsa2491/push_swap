/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/19 12:41:34 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_final_index(t_list **lst)
{
	t_list	*node;
	int		i;

	node = ft_find_min_node(*lst);
	i = 0;
	while (node)
	{
		node->final_index = i;
		node->index = -1;
		node->target = -1;
		node->price_a = -1;
		node->price_b = -1;
		node = ft_find_min_node(*lst);
		i += 1;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if ((!argv) || (argc == 2 && !argv[1][0]))
		ft_print_error();
	if (argc == 1)
		return (1);
	ft_check_params(argc, argv);
	if (argc > 2)
		ft_check_argc_more_than_two(argc, argv, &a);
	if (argc == 2)
		ft_check_argc_equal_two(argv, &a);
	ft_set_final_index(&a);
	if (!ft_is_list_sorted(&a))
		ft_push_swap(&a, &b);
	ft_clear_list(&a);
}
