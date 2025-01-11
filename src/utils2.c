/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:52 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:52 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_stack *stack, char list)
{
	t_list	*node;
	int		min;

	min = 2147483647;
	if (list == 'a')
		node = stack->a;
	else if (list == 'b')
		node = stack->b;
	else
		return (-1);
	while (node)
	{
		if (convert(node)->index < min)
			min = convert(node)->index;
		node = node->next;
	}
	return (min);
}

int	find_max(t_stack *stack, char list)
{
	t_list	*node;
	int		max;

	max = -2147483648;
	if (list == 'a')
		node = stack->a;
	else if (list == 'b')
		node = stack->b;
	else
		return (-1);
	while (node)
	{
		if (convert(node)->index > max)
			max = convert(node)->index;
		node = node->next;
	}
	return (max);
}

int	gen_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void	clear(t_stack *stack)
{
	ft_lstclear(&(stack -> a), del_content);
	ft_lstclear(&(stack -> b), del_content);
	free(stack);
}
