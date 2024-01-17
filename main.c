/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/12 17:02:44 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

static void	ft_check_params(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57) && argv[i][j] != '-' && argv[i][j] != 32)
				ft_print_error();
			j += 1;
		}
		i += 1;
	}
}

static void	ft_check_argc_more_than_two(int argc, char **argv, t_list **a)
{
	int		i;

	i = 1;
	*a = ft_lstnew(ft_atol(argv[1], a, NULL));
	i = 2;
	while (i < argc)
	{
		if (ft_handle_repetitions(*a, ft_atol(argv[i], a, NULL)))
		{
			ft_clear_list(a);
			ft_print_error();
		}
		ft_lstadd_back(a, ft_atol(argv[i], a, NULL));
		i += 1;
	}
}

static void	ft_check_argc_equal_two(char **argv, t_list **a)
{
	char	**tab;
	int		i;
	int		size;

	i = 1;
	size = ft_count_words(argv[1], 32);
	tab = ft_split(argv[1], 32);
	if (!tab || size == 0)
	{
		free(tab);
		ft_print_error();
	}
	*a = ft_lstnew(ft_atol(tab[0], a, tab));
	free(tab[0]);
	while (i < size)
	{
		if (ft_handle_repetitions(*a, ft_atol(tab[i], a, NULL)))
		{
			free(tab[i]);
			free(tab);
			ft_clear_list(a);
			ft_print_error();
		}
		ft_lstadd_back(a, ft_atol(tab[i], a, NULL));
		free(tab[i]);
		i += 1;
	}
	free(tab);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!argv)
		ft_print_error();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
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
