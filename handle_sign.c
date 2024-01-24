/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:22:47 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/24 15:01:48 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_sign_for_atol(char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

void	ft_handle_sign_repetition(char **tab, int j)
{
	if (tab)
	{
		while (tab[j])
			free(tab[j++]);
		free(tab);
		tab = NULL;
	}
}

void	ft_check_if_sign_or_space_at_the_beginning(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] == 32)
		i += 1;
	if (argv[1][i] == '-' && (argv[1][i + 1] == 32 || argv[1][i + 1] == '\0'))
		ft_print_error(NULL);
	if (argv[1][i] == '+' && (argv[1][i + 1] == 32 || argv[1][i + 1] == '\0'))
		ft_print_error(NULL);
}

void	ft_check_if_sign_or_space_at_the_end(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i][j] != '\0')
		j += 1;
	j -= 1;
	while (j >= 0)
	{
		while (argv[i][j] == 32)
			j -= 1;
		if (argv[i][j] == '+'
				&& (argv[i][j + 1] == 32 || argv[i][j + 1] == '\0'))
			ft_print_error(NULL);
		else if (argv[i][j] == '-'
				&& (argv[i][j + 1] == 32 || argv[i][j + 1] == '\0'))
			ft_print_error(NULL);
		j -= 1;
	}
}
