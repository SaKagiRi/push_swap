/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:50 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elements(t_stack *stack)
{
	int		max;
	t_list	*a;

	max = 0;
	a = stack->a;
	while (a)
	{
		if (convert(a)->index > max)
			max = convert(a)->index;
		a = a->next;
	}
	if (convert(ft_lstlast(stack->a))->index < max)
	{
		if (convert(stack->a)->index > convert(stack->a->next)->index)
			ra(stack);
		else
			rra(stack);
	}
	if (convert(stack->a)->index > convert(stack->a->next)->index)
		sa(stack);
}

void	sort_for_or_five(t_stack *stack)
{
	if (if_it_sort(stack, 'a', 0))
		return ;
	while (ft_lstsize(stack->b) < 2)
	{
		if (convert(stack->a)->index == 0 || convert(stack->a)->index == 1)
			pb(stack);
		else
			ra(stack);
	}
	if (convert(stack->b)->index == 0)
		sb(stack);
	sort_three_elements(stack);
	pa(stack);
	pa(stack);
}

void	gen_butterfly(t_stack *stack, int chunk)
{
	int		count;
	t_list	*a;

	a = stack->a;
	count = 0;
	while (a)
	{
		if (convert(a)->index <= count)
		{
			pb(stack);
			rb(stack);
			count++;
		}
		else if (convert(a)->index <= count + chunk)
		{
			pb(stack);
			count++;
		}
		else
			ra(stack);
		a = stack->a;
	}
}

void	pick_max_to_a(t_stack *stack)
{
	t_list	*node;
	int		sw;

	while (ft_lstsize(stack->b) != 0)
	{
		node = stack->b;
		set_median(stack);
		while (node)
		{
			if (convert(node)->index == find_max(stack, 'b'))
			{
				sw = (convert(node)->median == 1);
				while (convert(stack->b)->index != find_max(stack, 'b'))
				{
					if (sw == 1)
						rrb(stack);
					else
						rb(stack);
				}
			}
			node = node->next;
		}
		pa(stack);
	}
}

void	butterfly(t_stack *stack)
{
	int	chunk;

	if (if_it_sort(stack, 'a', 0))
		return ;
	chunk = gen_chunk(ft_lstsize(stack->a));
	gen_butterfly(stack, chunk);
	pick_max_to_a(stack);
}
