/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:18:01 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/24 14:41:22 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_params(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[1][i] == 32)
		i += 1;
	if (argv[1][i] == '-' && (argv[1][i + 1] == 32 || argv[1][i + 1] == '\0'))
		ft_print_error(NULL);
	if (argv[1][i] == '+' && (argv[1][i + 1] == 32 || argv[1][i + 1] == '\0'))
		ft_print_error(NULL);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57)
			&& argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != 32)
				ft_print_error(NULL);
			ft_check_if_sign_or_space_at_the_end(argv);
			j += 1;
		}
		i += 1;
	}
}

void	ft_check_argc_more_than_two(int argc, char **argv, t_list **a)
{
	int		i;

	i = 1;
	*a = ft_lstnew(ft_atol(argv[1], a, NULL, 0));
	i = 2;
	while (i < argc)
	{
		if (ft_handle_repetitions(*a, ft_atol(argv[i], a, NULL, i)))
		{
			ft_clear_list(a);
			ft_print_error(NULL);
		}
		ft_lstadd_back(a, ft_atol(argv[i], a, NULL, i));
		i += 1;
	}
}

static int	ft_check_if_first_param_overflow(char *str)
{
	int		i;
	long	base;
	int		sign;

	i = 0;
	base = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		base = base * 10 + (str[i] - 48);
		i += 1;
	}
	base = sign * base;
	if (base < INT_MIN || base > INT_MAX)
	{
		return (0);
	}
	return (1);
}

static void	ft_fill_list_when_split(char **tab, int size, t_list **a)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_handle_repetitions(*a, ft_atol(tab[i], a, tab, i)))
		{
			while (tab[i])
				free(tab[i++]);
			free(tab);
			ft_clear_list(a);
			ft_print_error(NULL);
		}
		ft_lstadd_back(a, ft_atol(tab[i], a, tab, i));
		free(tab[i]);
		tab[i] = NULL;
		i += 1;
	}
}

void	ft_check_argc_equal_two(char **argv, t_list **a)
{
	char	**tab;
	int		size;

	if (!ft_check_if_first_param_overflow(argv[1]))
		ft_print_error(NULL);
	size = ft_count_words(argv[1], 32);
	tab = ft_split(argv[1], 32);
	if (!tab || size == 0)
	{
		free(tab);
		ft_print_error(NULL);
	}
	*a = ft_lstnew(ft_atol(tab[0], a, tab, 0));
	free(tab[0]);
	tab[0] = NULL;
	ft_fill_list_when_split(tab, size, a);
	free(tab);
	tab = NULL;
}
