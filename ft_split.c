/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:05 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/06 16:51:47 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_fill_tab(char *s, char c)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_count_size_of_word(s, c);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		str[i] = s[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

static void	*ft_free_tab(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		tab[j] = NULL;
		j += 1;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static char	**ft_define_tab(char *str, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	tab = ft_define_tab(str, c);
	tab[ft_count_words(str, c)] = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			tab[j] = ft_fill_tab(&str[i], c);
			if (!tab[j++])
				return (ft_free_tab(tab, j));
			while (str[i] != '\0' && str[i] != c)
				i += 1;
		}
		else
			i += 1;
	}
	return (tab);
}
