/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:06 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:54:06 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	numformat(char *nb)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(nb);
	if (len == 1 && (nb[0] == '-' || nb[0] == '+'))
		return (0);
	while (nb[++i])
	{
		if ((nb[i] == '-' || nb[i] == '+') && i != 0)
			return (0);
		if (!((nb[i] >= '0' && nb[i] <= '9') || (nb[i] == '+' || nb[i] == '-')))
			return (0);
	}
	return (1);
}

int	checkparser(char **v)
{
	t_check	check;

	check.i = -1;
	while (v[++check.i])
	{
		if (ft_strchr(v[check.i], ' ') != NULL)
		{
			check.numpack = ft_split(v[check.i], ' ');
			check.j = 0;
			while (check.numpack[check.j])
			{
				if (numformat(check.numpack[check.j++]) == 0)
				{
					free_split(check.numpack);
					return (0);
				}
			}
			free_split(check.numpack);
		}
		else
			if (numformat(v[check.i]) == 0)
				return (0);
	}
	return (1);
}

void	check_same_number(t_stack *stack)
{
	t_list	*a;
	t_list	*temp;
	int		num;
	int		status;

	a = stack -> a;
	while (a)
	{
		status = 0;
		num = ((t_content *)a->content)->number;
		temp = stack -> a;
		while (temp)
		{
			if (((t_content *)temp->content)->number == num)
				status++;
			if (status == 2)
			{
				clear(stack);
				write(2, "Error\n", 6);
				exit(1);
			}
			temp = temp -> next;
		}
		a = a -> next;
	}
}

int	ft_atol(char *nb, t_stack *stack, char **split)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (nb[i] == ' ' || (nb[i] >= '\t' && nb[i] <= '\r'))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		if (nb[i++] == '-')
			sign = -1;
	while (nb[i])
	{
		res = res * 10 + (nb[i++] - '0');
		if (res > 2147483647 || res * sign < -2147483648 || ft_strlen(nb) > 11)
		{
			clear(stack);
			free_split(split);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return ((int)res * sign);
}

void	add_number_to_stack(t_stack *stack, char **v)
{
	t_check	check;

	check.i = -1;
	while (v[++check.i])
	{
		if (ft_strchr(v[check.i], ' ') != NULL)
		{
			check.numpack = ft_split(v[check.i], ' ');
			check.j = 0;
			while (check.numpack[check.j])
				ft_lstadd_back(&(stack -> a), ft_lstnew(add_content \
					(ft_atol(check.numpack[check.j++], \
						stack, check.numpack), 0)));
			free_split(check.numpack);
		}
		else
		{
			check.numpack = ft_split("temp temp", ' ');
			ft_lstadd_back(&(stack -> a), ft_lstnew(add_content \
				(ft_atol(v[check.i], stack, check.numpack), 0)));
			free_split(check.numpack);
		}
	}
	check_same_number(stack);
}
