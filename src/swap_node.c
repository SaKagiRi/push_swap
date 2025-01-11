/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:51 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_list(t_list **node)
{
	t_list	*temp;

	if (!(*node) || !(*node)->next)
		return (0);
	temp = (*node)->next;
	(*node)->next = temp->next;
	temp->next = *node;
	*node = temp;
	return (1);
}

void	sa(t_stack *stack)
{
	int	status;

	status = swap_list(&(stack -> a));
	if (SHOW_OPERATION && status)
		pnf("sa\n");
}

void	sb(t_stack *stack)
{
	int	status;

	status = swap_list(&(stack -> b));
	if (SHOW_OPERATION && status)
		pnf("sb\n");
}

void	ss(t_stack *stack)
{
	int	status_a;
	int	status_b;

	status_a = swap_list(&(stack -> a));
	status_b = swap_list(&(stack -> b));
	if (SHOW_OPERATION && status_a && status_b)
		pnf("ss\n");
}
