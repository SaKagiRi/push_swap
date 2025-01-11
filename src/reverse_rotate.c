/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:48 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:48 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reverse_rotate_list(t_list **node)
{
	t_list	*temp;
	t_list	*last;
	int		i;

	if (!(*node))
		return (0);
	if (!(*node)->next)
		return (0);
	temp = *node;
	last = ft_lstlast(*node);
	i = ft_lstsize(*node);
	while (i-- > 2)
		*node = (*node)->next;
	(*node)->next = NULL;
	*node = temp;
	ft_lstadd_front(node, last);
	return (1);
}

void	rra(t_stack *stack)
{
	int	status;

	status = reverse_rotate_list(&(stack -> a));
	if (SHOW_OPERATION && status)
		pnf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	status;

	status = reverse_rotate_list(&(stack -> b));
	if (SHOW_OPERATION && status)
		pnf("rrb\n");
}

void	rrr(t_stack *stack)
{
	int	status_a;
	int	status_b;

	status_a = reverse_rotate_list(&(stack -> a));
	status_b = reverse_rotate_list(&(stack -> b));
	if (SHOW_OPERATION && status_a && status_b)
		pnf("rrr\n");
}
