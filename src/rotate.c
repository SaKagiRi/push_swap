/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:49 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:49 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate(t_list **node)
{
	t_list	*temp;

	if (!(*node))
		return (0);
	if (!(*node)->next)
		return (0);
	temp = *node;
	*node = (*node)->next;
	temp -> next = NULL;
	ft_lstadd_back(node, temp);
	return (1);
}

void	ra(t_stack *stack)
{
	int	status;

	status = rotate(&(stack -> a));
	if (SHOW_OPERATION && status)
		pnf("ra\n");
}

void	rb(t_stack *stack)
{
	int	status;

	status = rotate(&(stack -> b));
	if (SHOW_OPERATION && status)
		pnf("rb\n");
}

void	rr(t_stack *stack)
{
	int	status_a;
	int	status_b;

	status_a = rotate(&(stack -> a));
	status_b = rotate(&(stack -> b));
	if (SHOW_OPERATION && status_a && status_b)
		pnf("rr\n");
}
