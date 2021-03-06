/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:00:14 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/28 16:00:17 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_4_args(t_status_lists **list)
{
	int			count;
	t_init_list	*tmp;

	tmp = (*list)->begin_A;
	count = list_size(list);
	while (count != 3)
	{
		if ((tmp->index_sort) == 1)
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
	push_A(list);
}
