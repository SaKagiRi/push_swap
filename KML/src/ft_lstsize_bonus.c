/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:00:24 by knakto            #+#    #+#             */
/*   Updated: 2024/09/05 11:03:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
