/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:10:04 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 12:12:08 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_A(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_A == NULL)
		return ;
	tmp = (*list)->begin_A;
	(*list)->begin_A = (*list)->begin_A->next;
	(*list)->last_A->next = tmp;
	(*list)->last_A = tmp;
	(*list)->last_A->next = NULL;
}

void	rotate_B(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_B == NULL)
		return ;
	tmp = (*list)->begin_B;
	(*list)->begin_B = (*list)->begin_B->next;
	(*list)->last_B->next = tmp;
	(*list)->last_B = tmp;
	(*list)->last_B->next = NULL;
}

void	rotate_R(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_B == NULL || (*list)->begin_A == NULL)
		return ;
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
}

void	rotate_RA(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_A == NULL)
		return ;
	tmp = (*list)->begin_A;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(*list)->last_A->next = (*list)->begin_A;
	(*list)->begin_A = (*list)->last_A;
	(*list)->last_A = tmp;
}

void	rotate_RB(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_B == NULL)
		return ;
	tmp = (*list)->begin_B;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(*list)->last_B->next = (*list)->begin_B;
	(*list)->begin_B = (*list)->last_B;
	(*list)->last_B = tmp;
}
