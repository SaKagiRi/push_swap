/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:50:08 by knakto            #+#    #+#             */
/*   Updated: 2025/01/18 11:50:08 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	it_operator(char *line, t_stack *stack)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stack);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack);
	else
		return (0);
	return (1);
}

void	checker(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (it_operator(line, stack) != 1)
		{
			free(line);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

void	print(t_stack *stack)
{
	t_list	*a;

	a = stack->a;
	while (a)
	{
		pnf("%d ", convert(a)->number);
		a = a->next;
	}
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
	checker(stack);
	if (if_it_sort(stack, 'a', 0))
		pnf("OK\n");
	else
		pnf("KO");
	return (0);
}
