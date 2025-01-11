/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:47 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:47 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	controller(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 1)
	{
		clear(stack);
		exit(0);
	}
	else if (size <= 3)
		sort_three_elements(stack);
	else if (size <= 5)
		sort_for_or_five(stack);
	else
		butterfly(stack);
}

int	not_number(char **v)
{
	int	i;
	int	j;

	i = -1;
	while (v[++i])
	{
		j = -1;
		while (v[i][++j])
		{
			if (v[i][j] >= '0' && v[i][j] <= '9')
				return (0);
		}
	}
	return (1);
}

int	main(int c, char **v)
{
	t_stack	*stack;

	if (c < 2 || not_number(v) || !checkparser(v + 1))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack -> a = NULL;
	stack -> b = NULL;
	add_number_to_stack(stack, v + 1);
	sort_index(stack);
	controller(stack);
	clear(stack);
	return (0);
}
