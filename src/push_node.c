/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:37 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:37 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_list(t_list **push, t_list **pull)
{
	t_list	*temp;

	if (!(*push))
		return (0);
	temp = (*push)->next;
	ft_lstadd_front(pull, *push);
	*push = temp;
	return (1);
}

void	pa(t_stack *stack)
{
	int	status;

	status = push_list(&(stack -> b), &(stack -> a));
	if (SHOW_OPERATION && status)
		pnf("pa\n");
	else if (SHOW_OPERATION)
		pnf("[pa] failed\n");
}

void	pb(t_stack *stack)
{
	int	status;

	status = push_list(&(stack -> a), &(stack -> b));
	if (SHOW_OPERATION && status)
		pnf("pb\n");
	else if (SHOW_OPERATION)
		pnf("[pb] failed\n");
}
