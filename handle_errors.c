/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:59:03 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/19 18:28:12 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i += 1;
	}
}

void	ft_print_error(char **tab)
{
	int	i;

	i = 1;
	if (tab && tab[0])
		free(tab[0]);
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

static void	ft_check_overflow(long base, t_list **lst, char **tab, int i)
{
	if (base < INT_MIN || base > INT_MAX)
	{
		if (tab)
		{
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i += 1;
			}
			free(tab);
			tab = NULL;
			ft_clear_list(lst);
			ft_print_error(NULL);
		}
		else
		{
			ft_clear_list(lst);
			ft_print_error(NULL);
		}
	}
}

long	ft_atol(char *str, t_list **lst, char **tab, int j)
{
	int		i;
	long	base;
	int		sign;

	i = 0;
	base = 0;
	sign = 1;
	ft_handle_sign(str, &i, &sign);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			base = base * 10 + (str[i] - 48);
		else
		{
			ft_clear_list(lst);
			ft_print_error(tab);
		}		
		i += 1;
	}
	base = base * sign;
	ft_check_overflow(base, lst, tab, j);
	return (base);
}

int	ft_handle_repetitions(t_list *node, int nb)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->content == nb)
			return (1);
		node = node->next;
	}
	return (0);
}
