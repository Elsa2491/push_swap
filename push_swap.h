/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:44:20 by eltouma           #+#    #+#             */
/*   Updated: 2023/11/20 19:29:13 by eltouma          ###   ########.fr       */
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
	int				relative_to_median;
// pas sur d'en avoir besoin. Poss de le remplacer par l'index dans ft_set_position_to_median
	int				above_median;
	int				price;
	int				cheapest;
// a initialiser dans lstnew()
	struct s_list	*target;
	struct s_list	*next;
}		t_list;

void	ft_delete_last(t_list **list);
void	ft_delete_first(t_list **list);
void	ft_clear_list(t_list *node);

char	*ft_fill_tab(char *s, char c);
void	*ft_free_tab(char **tab, int i);
char	**ft_define_tab(char *str, char c);
int		ft_strlen(char *str);
int		ft_count_words(char *str, char c);
int		ft_count_size_of_word(char *str, char c);
char	*ft_fill_tab(char *s, char c);
char	**ft_split(char *str, char c);

void	ft_print_error(void);
long	ft_atol(char *str);
int		ft_handle_repetitions(t_list *node, int nb);

int		ft_is_list_sorted(t_list **lst);
void	ft_sort_three(t_list **lst);
void	ft_sort_five(t_list **lst_a, t_list **lst_b);

t_list	*ft_find_min_node(t_list *node);
t_list	*ft_find_max_node(t_list *node);
int		ft_min(t_list *node);
int		ft_max(t_list *node);
int		ft_find_median(t_list *node);

void	ft_swap_first_values(t_list *node);
void	ft_push(t_list **lst_from, t_list **lst_to_push);
void	ft_print_list(t_list *node);
void	ft_push_swap(t_list **lst_a, t_list **lst_b);

void	ft_set_position_relative_to_median(t_list *node);
void	ft_find_target_node(t_list *node_a, t_list *node_b);
void	ft_set_price(t_list *node_a, t_list *node_b);
void	ft_set_cheapest_node(t_list *node);
void	ft_initialize_nodes(t_list *node_a, t_list *node_b);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *node);
void	ft_lstadd_back(t_list **list, int nb);
void	ft_lstadd_front(t_list **list, t_list *new_node);
int		ft_lstsize(t_list *node);

void	ft_swap_first_and_last(t_list **list);
void	ft_reverse_rotate(t_list **list);
void	ft_reverse_rotate_both(t_list **lst_a, t_list **lst_b);
void	ft_rotate(t_list **list);
void	ft_rotate_both(t_list **lst, t_list **lst_b);
void	ft_finish_rotation(t_list **lst, t_list *node, char lst_name);

t_list	*ft_find_cheapest_node(t_list *node);
void	ft_move_nodes(t_list **lst_a, t_list **lst_b);
#endif
