/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:59:03 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/18 18:47:28 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_putstr_fd(char *s, int fd)
{
    int     i;

    i = 0;
    if (!s)
        return ;
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i += 1;
    }
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

long	ft_atol(char *str, t_list **lst, char **tab)
{
	int		i;
	long	base;
	int		sign;

	i = 0;
	base = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			base = base * 10 + (str[i] - 48);
		else
			ft_print_error();
		i += 1;
	}
	base = base * sign;
	if (base < INT_MIN || base > INT_MAX)
	{
		if (tab)
		{
			for(int i = 1; tab[i]; i++)
			{
				free(tab[i]);
			}
			free(tab);
			ft_clear_list(lst);
			ft_print_error();
		}
		else
		{
			ft_clear_list(lst);
			ft_print_error();
		}
	}
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
