/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <kasichonooo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:52:59 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:53:43 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_number_after_min(t_stack *stack, int min)
{
	t_list	*a;
	int		number;
	int		content;

	a = stack -> a;
	number = 2147483647;
	while (a)
	{
		content = ((t_content *)a->content)->number;
		if (content < number && content > min)
			number = content;
		a = a->next;
	}
	return (number);
}

void	sort_index(t_stack *stack)
{
	t_list	*a;
	t_list	*temp;
	int		num;
	int		i;

	a = stack->a;
	num = -2147483648;
	i = 0;
	while (a)
	{
		num = find_number_after_min(stack, num);
		temp = stack->a;
		while (temp)
		{
			if (((t_content *)temp->content)->number == num)
				((t_content *)temp->content)->index = i++;
			temp = temp->next;
		}
		a = a->next;
	}
}
