/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:11 by knakto            #+#    #+#             */
/*   Updated: 2025/01/11 18:55:11 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../KML/include/kml.h"

# ifndef SHOW_OPERATION
#  define SHOW_OPERATION 1
# endif

typedef struct s_content
{
	char	median;
	int		number;
	int		index;
}	t_content;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_check
{
	int		i;
	int		j;
	char	**numpack;
}	t_check;

int			numformat(char *nb);
int			checkparser(char **v);
t_content	*add_content(int number, int index);
void		del_content(void *content);
void		clear(t_stack *stack);
void		add_number_to_stack(t_stack *stack, char **v);
t_content	*convert(t_list *a);
int			if_it_sort(t_stack *stack, char list, int reverse);
int			find_min(t_stack *stack, char list);
int			find_max(t_stack *stack, char list);
int			find_number_after_min(t_stack *stack, int min);
int			not_number(char **v);

int			swap_list(t_list **node);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);

int			push_list(t_list **push, t_list **pull);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

int			rotate(t_list **node);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);

int			reverse_rotate_list(t_list **node);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

void		sort_index(t_stack *stack);
void		sort_three_elements(t_stack *stack);
void		sort_for_or_five(t_stack *stack);

int			gen_chunk(int size);
void		butterfly(t_stack *stack);
void		set_median(t_stack *stack);

#endif
