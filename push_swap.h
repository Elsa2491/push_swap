/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:44:20 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/09 18:27:05 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				a_price
	int				b_price;
	int				total_price;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *node);
void	ft_lstadd_back(t_list **list, int nb);
void	ft_lstadd_front(t_list **list, t_list *new_node);
void	ft_delete_last(t_list **list);
void	ft_delete_first(t_list **list);
void	ft_swap_first_values(t_list *node);
void	ft_push(t_list **lst_from, t_list **lst_to_push);
void	ft_print_list(t_list *node);
void	ft_swap_first_and_last(t_list **list);
void	ft_reverse_rotate(t_list **list);
void	ft_rotate(t_list **list);
t_list	*ft_find_min_node(t_list *node);
int		ft_min(t_list *node);
int		ft_max(t_list *node);
void	ft_push_until_three_nodes_left(t_list **lst_a, t_list **lst_b);
void	ft_sort_three(t_list **lst);
int		ft_lstsize(t_list *node);
char	**ft_split(char *str, char c);
void	ft_find_cheapest_cost(t_list *node_a, t_list *node_b);
int		ft_strlen(char *str);
int		ft_count_words(char *str, char c);
int		ft_count_size_of_word(char *str, char c);
char	*ft_fill_tab(char *s, char c);
void	*free_tab(char **tab, int i);
char	**ft_define_tab(char *str, char c);
int		ft_is_list_sorted(t_list **lst);
void	ft_set_index(t_list *node);
int		ft_find_median(t_list *node);
t_list	*ft_find_target_node(t_list *node_a, t_list *node_b);
long	ft_atol(char *str);
int		ft_handle_repetitions(t_list *node, int nb);
void	ft_print_error(void);
void	ft_test(t_list *a, t_list *b);
#endif
