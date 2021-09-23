/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:10:04 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/23 17:12:01 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_A(t_status_lists **list)
{
	t_init_list	*tmp;

	tmp = (*list)->begin_A;
	(*list)->begin_A = (*list)->begin_A->next;
	(*list)->last_A->next = tmp;
	(*list)->last_A = tmp;
	(*list)->last_A->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_B(t_status_lists **list)
{
	t_init_list	*tmp;

	tmp = (*list)->begin_B;
	(*list)->begin_B = (*list)->begin_B->next;
	(*list)->last_B->next = tmp;
	(*list)->last_B = tmp;
	(*list)->last_B->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_R(t_status_lists **list)
{
	t_init_list	*tmp;

	tmp = (*list)->begin_A;
	(*list)->begin_A = (*list)->begin_A->next;
	(*list)->last_A->next = tmp;
	(*list)->last_A = tmp;
	(*list)->last_A->next = NULL;
	tmp = (*list)->begin_B;
	(*list)->begin_B = (*list)->begin_B->next;
	(*list)->last_B->next = tmp;
	(*list)->last_B = tmp;
	(*list)->last_B->next = NULL;
	write(1, "rr\n", 3);
}

void	rotate_RA(t_status_lists **list)
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
	write(1, "rra\n", 4);
}

void	rotate_RB(t_status_lists **list)
{
	t_init_list	*tmp;

	tmp = (*list)->begin_B;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(*list)->last_B->next = (*list)->begin_B;
	(*list)->begin_B = (*list)->last_B;
	(*list)->last_B = tmp;
	write(1, "rrb\n", 4);
}
