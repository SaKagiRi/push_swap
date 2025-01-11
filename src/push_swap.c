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

void	clear(t_stack *stack)
{
	ft_lstclear(&(stack -> a), del_content);
	ft_lstclear(&(stack -> b), del_content);
	free(stack);
}

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

int	main(int c, char **v)
{
	t_stack	*stack;
	t_list	*tmp;
	void	*temp[2];
	int		i;
	long	**num;

	if (!checkparser(v + 1) || c < 2)
		return (pnf("error\n"));
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack -> a = NULL;
	stack -> b = NULL;
	add_number_to_stack(stack, v + 1);
	sort_index(stack);
	controller(stack);
	clear(stack);
	return (0);
}
