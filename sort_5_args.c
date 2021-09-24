/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:26:08 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/24 17:34:27 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	chek_and_push_a(t_status_lists **list)
{
	if ((*list)->begin_B->index_sort < (*list)->last_B->index_sort)
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
			count--;
		}
		else
		{
			tmp = tmp->next;
			rotate_A(list);
		}		
	}
	sort_3_args(list);
	chek_and_push_a(list);
}
