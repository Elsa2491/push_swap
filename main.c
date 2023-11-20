/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/20 19:44:00 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tab;
	int		i;
	int		size;

	a = NULL;
	b = NULL;
	i = 1;
	if (!argv)
		ft_print_error();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	size = ft_count_words(argv[1], 32);
	if (argc > 2)
	{
		a = ft_lstnew(ft_atol(argv[i]));
		i = 2;
		while (i < argc)
		{
			if (ft_handle_repetitions(a, ft_atol(argv[i])))
				ft_print_error();
			ft_lstadd_back(&a, ft_atol(argv[i]));
			i += 1;
		}
	}
	else if (argc == 2)
	{
		tab = ft_split(argv[1], 32);
		if (!tab)
			ft_print_error();
		a = ft_lstnew(ft_atol(tab[0]));
		while (i < size)
		{
			if (ft_handle_repetitions(a, ft_atol(tab[i])))
				ft_print_error();
			ft_lstadd_back(&a, ft_atol(tab[i]));
			i += 1;
		}
	}
	printf("AVANT LE TRI\nlist a\n");
	ft_print_list(a);
	printf("\n");
	printf("list b\n");
	ft_print_list(b);
	printf("\n");
	printf("\n");

	if (!ft_is_list_sorted(&a))
	{
		if (ft_lstsize(a) <= 3)
			ft_sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}

	printf("\n");
	printf("\nAPRES LE TRI\nlist a\n");
	ft_print_list(a);
	printf("\n");
	printf("list b\n");
	ft_print_list(b);
	printf("\n\n");
	ft_is_list_sorted(&a);

}
