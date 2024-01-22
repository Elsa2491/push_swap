/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:44:20 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/19 18:24:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				price_a;
	int				price_b;
	int				price;
	int				final_index;
	int				index;
	int				target;
	struct s_list	*next;
}		t_list;

void	ft_check_params(int argc, char **argv);
void	ft_check_argc_more_than_two(int argc, char **argv, t_list **a);
void	ft_check_argc_equal_two(char **argv, t_list **a);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **list, int nb);
void	ft_lstadd_front(t_list **list, t_list *new_node);
int		ft_lstsize(t_list *node);
void	ft_delete_last(t_list **list);
void	ft_delete_first(t_list **list);
void	ft_clear_list(t_list **lst);

int		ft_count_words(char *str, char c);
int		ft_count_size_of_word(char *str, char c);
char	**ft_split(char *str, char c);
void	ft_print_error(char **tab);
long	ft_atol(char *str, t_list **lst, char **tab, int j);
int		ft_handle_repetitions(t_list *node, int nb);

int		ft_is_list_sorted(t_list **lst);
void	ft_little_sorting(t_list **lst_a, t_list **lst_b);
t_list	*ft_find_min_node(t_list *node);
int		ft_min(t_list *node);
int		ft_max(t_list *node);
int		ft_get_distance_from_min(t_list **lst, int min);
int		ft_find_median(t_list *node);
int		ft_set_pos(int nb);

void	ft_init_index(t_list **lst);
void	ft_get_target(t_list **lst_a, t_list **lst_b);
void	ft_set_price(t_list **lst_a, t_list **lst_b);
void	ft_less_move(t_list **lst_a, t_list **lst_b);
void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst_a);
void	rrb(t_list **lst_a);
void	ft_exec(t_list **lsta_, t_list **lst_b, int cost_a, int cost_b);
void	ft_rev_rotate_both(t_list **a, t_list **b, int *price_b, int *price_a);
void	ra(t_list **lst_a);
void	rb(t_list **lst_a);
void	ft_rotate_both(t_list **a, t_list **b, int *price_b, int *price_a);
void	ft_swap_first_values(t_list **node);
void	ft_swap_first_and_last(t_list **list);
void	pb(t_list **from_a, t_list **to_b);
void	pa(t_list **from_b, t_list **to_a);
void	ft_push_swap(t_list **lst_a, t_list **lst_b);
void	sa(t_list **list);
#endif
