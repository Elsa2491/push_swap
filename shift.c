#include "push_swap.h"

t_list	*ft_find_cheapest_node(t_list *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	ft_move_nodes(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest_node(*lst_b);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		ft_reverse_rotate(lst_a);
		ft_reverse_rotate(lst_b);
	}
	ft_finish_rotation(lst_b, cheapest, 'b');
	ft_finish_rotation(lst_a, cheapest->target, 'a');
	ft_push(lst_b, lst_a);
}
