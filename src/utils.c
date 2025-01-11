/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:51 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del_content(void *content)
{
	free(content);
}

t_content	*convert(t_list *a)
{
	return ((t_content *)a->content);
}

int	if_it_sort(t_stack *stack, char list, int reverse)
{
	t_list	*node;
	int		i;

	i = -1;
	if (list == 'a')
		node = stack->a;
	else if (list == 'b')
		node = stack->b;
	while (node)
	{
		if (reverse == 0)
		{
			if (convert(node)->index <= i)
				return (0);
			i = convert(node)->index;
		}
		else
		{
			if (convert(node)->index >= i)
				return (0);
			i = convert(node)->index;
		}
		node = node->next;
	}
	return (1);
}

t_content	*add_content(int number, int index)
{
	t_content	*content;

	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->number = number;
	content->index = index;
	return (content);
}
