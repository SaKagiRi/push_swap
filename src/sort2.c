/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:50 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_median(t_stack *stack)
{
	t_list	*node;
	int		size;
	int		sw;
	int		i;

	sw = 0;
	while (sw++ < 2)
	{
		node = stack->a;
		if (sw == 2)
			node = stack->b;
		size = ft_lstsize(node) / 2;
		if (ft_lstsize(node) % 2 == 0)
			size--;
		i = 0;
		while (node)
		{
			convert(node)->median = 0;
			if (i++ > size)
				convert(node)->median = 1;
			node = node->next;
		}
	}
}
