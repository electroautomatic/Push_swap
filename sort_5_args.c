/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:26:08 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/23 16:26:14 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_5_args(t_status_lists **list)
{
	int			count;
	t_init_list	*tmp;

	tmp = (*list)->begin_A;
	count = list_size(list);
	while (count != 3)
	{
		if ((tmp->index_sort) == 1 || (tmp->index_sort) == 2)
		{
			tmp = tmp->next;
			push_B(list);
		}
		else
		{
			tmp = tmp->next;
			rotate_A(list);
		}
		count = list_size(list);
	}
	if ((*list)->begin_B < (*list)->last_B)
	{
		swap_B(list);
		push_A(list);
		push_A(list);
	}
	else
	{
		push_A(list);
		push_A(list);
	}
}
