/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/19 13:20:44 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_params(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57)
			&& argv[i][j] != '-' && argv[i][j] != 32)
				ft_print_error();
			j += 1;
		}
		i += 1;
	}
}

void	ft_check_argc_more_than_two(int argc, char **argv, t_list **a)
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

static long	ft_check_if_first_param_overflow(char *nptr)
{
        int     i;
        long    base;
        int     sign;

        i = 0;
        base = 0;
        sign = 1;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
                if (nptr[i] == '-')
                        sign *= -1;
                i += 1;
        }
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                base = base * 10 + (nptr[i] - '0');
                i += 1;
        }
        base = sign * base;
        if (base < INT_MIN || base > INT_MAX)
        {
//		ft_printf("coucou petit overflow %lu\n", base);
  //              ft_printf("reponse du code : non\n");
		return (0);
        }
//	ft_printf("coucou %lu\n", base);
        return (1);
}

void	ft_check_argc_equal_two(char **argv, t_list **a)
{
	char	**tab;
	int		i;
	int		size;

	i = 1;
	if (!ft_check_if_first_param_overflow(argv[1]))
		ft_print_error();
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
		if (ft_handle_repetitions(*a, ft_atol(tab[i], a, tab)))
		{
			free(tab[i]);
			free(tab);
			ft_clear_list(a);
			ft_print_error();
		}
		ft_lstadd_back(a, ft_atol(tab[i], a, tab));
		free(tab[i]);
		i += 1;
	}
	free(tab);
}
