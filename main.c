/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/10/18 16:54:13 by eltouma          ###   ########.fr       */
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
	size = ft_count_words(argv[1], ' ');
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
		tab = ft_split(argv[1], ' ');
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
	printf("list a\n");
	ft_print_list(a);
	printf("\n");
	printf("list b\n");
	ft_print_list(b);
	printf("\n");
	printf("\n");
	ft_is_list_sorted(&a);
	printf("\n");
	ft_find_index(a, ft_lstsize(a) - 1);
	ft_find_median(a);
	ft_push_until_three_nodes_left(&a, &b);
	ft_find_target_node(a, b);
	ft_is_list_sorted(&a);
	printf("list a\n");
	ft_print_list(a);
	printf("\n");
	printf("list b\n");
	ft_print_list(b);
	printf("\n");
}

/*
   int	main(void)
   {
   t_list *a;
   t_list *b;
// ----------------------------------------------- TESTS SUJET ----------------------------------------------- 
a = ft_lstnew(2);
b = NULL;
ft_lstadd_back(&a, 1);
ft_lstadd_back(&a, 3);
ft_lstadd_back(&a, 6);
ft_lstadd_back(&a, 5);
ft_lstadd_back(&a, 8);
printf("Init a and b:\n");
ft_print_list(a);
printf("- -\n");
printf("a b");
printf("\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Exec sa:\n");
ft_swap_first_values(a);
ft_print_list(a);
printf("- -\n");
printf("a b\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Exec pb pb pb:\n");
ft_push(&a, &b);
ft_push(&a, &b);
ft_push(&a, &b);
ft_print_list(a);
printf("-\n");
printf("a\n\n");
ft_print_list(b);
printf("-\n");
printf("b\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Exec ra rb (equiv. to rr):\n");
ft_rotate(&a);
ft_print_list(a);
printf("-\n");
printf("a\n\n");
ft_rotate(&b);
ft_print_list(b);
printf("-\n");
printf("b\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Exec rra rrb (equiv. to rrr):\n");
ft_reverse_rotate(&a);
ft_print_list(a);
printf("-\n");
printf("a\n\n");
ft_reverse_rotate(&b);
ft_print_list(b);
printf("-\n");
printf("b\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Execute sa:\n");
ft_swap_first_values(a);
ft_print_list(a);
printf("-\n");
printf("a\n\n");
ft_print_list(b);
printf("-\n");
printf("b\n");
printf("---------------------------------------------------------------------------\n\n");
printf("Exec pa pa pa:\n");
ft_push(&b, &a);
ft_push(&b, &a);
ft_push(&b, &a);
ft_print_list(a);
printf("- -\n");
printf("a b\n\n");
printf("---------------------------------------------------------------------------\n\n");
*/
// ----------------------------------------------- TESTS FUNCTIONS ----------------------------------------------- 

/*
   int	main(void)
   {
   t_list *a;
   t_list *b;
   a = ft_lstnew(99);
   b = NULL;
   ft_lstadd_back(&a, 100);
   ft_lstadd_back(&a, 525);
   ft_lstadd_back(&a, -38);
   ft_lstadd_back(&a, 10);
   ft_lstadd_back(&a, 7);
   ft_lstadd_back(&a, 42);
   printf("a\n");
   printf("-\n");
   ft_print_list(a);
   printf("\n");
   printf("------------\n");
   printf("b\n");
   printf("-\n");
   ft_print_list(b);
   printf("\n\n");
   printf("\n\nExec find_target_node\n");
   printf("Tri de la liste en cours\n");
   printf("\n---------------------------------------------------------------------------\n\n");
//	printf("La mediane de a est : %ld\n", ft_find_median(a));
ft_find_target_node(&a, &b);
printf("a\n");
printf("-\n");
ft_print_list(a);
printf("\n");
printf("------------\n");
printf("b\n");
printf("-\n");
ft_print_list(b);
printf("last_node : %d\n", ft_lstlast(a)->content);
printf("\n\n");
}
 */
