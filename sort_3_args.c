/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:27:13 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/23 17:34:02 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_3_args(t_status_lists **list)
{
	if (!sort_or_not((*list)->begin_A))
	{
		if (((*list)->begin_A->value > (*list)->begin_A->next->value) && \
		((*list)->begin_A->value < (*list)->last_A->value) && \
		((*list)->last_A->value > (*list)->begin_A->next->value))
		{
			swap_A(list);
		}
		else if (((*list)->begin_A->value > (*list)->begin_A->next->value) && \
		((*list)->begin_A->value > (*list)->last_A->value) && \
		((*list)->last_A->value < (*list)->begin_A->next->value))
		{
			swap_A(list);
			rotate_RA(list);
		}
		else if (((*list)->begin_A->value > (*list)->begin_A->next->value) && \
		((*list)->begin_A->value > (*list)->last_A->value) && \
		((*list)->last_A->value > (*list)->begin_A->next->value))
		{
			rotate_A(list);
		}
		else if (((*list)->begin_A->value < (*list)->begin_A->next->value) && \
		((*list)->begin_A->value < (*list)->last_A->value) && \
		((*list)->last_A->value < (*list)->begin_A->next->value))
		{
			swap_A(list);
			rotate_A(list);
		}
		else if (((*list)->begin_A->value < (*list)->begin_A->next->value) && \
		((*list)->begin_A->value > (*list)->last_A->value) && \
		((*list)->last_A->value < (*list)->begin_A->next->value))
		{
			rotate_RA(list);
		}
	}
}
