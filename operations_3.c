/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:11:34 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/23 17:11:54 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_RR(t_status_lists **list)
{
	t_init_list	*tmp;

	tmp = (*list)->begin_A;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(*list)->last_A->next = (*list)->begin_A;
	(*list)->begin_A = (*list)->last_A;
	(*list)->last_A = tmp;
	tmp = NULL;
	tmp = (*list)->begin_B;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(*list)->last_B->next = (*list)->begin_B;
	(*list)->begin_B = (*list)->last_B;
	(*list)->last_B = tmp;
	write(1, "rrr\n", 4);
}
