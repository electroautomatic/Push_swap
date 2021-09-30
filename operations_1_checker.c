/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:28:37 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/30 12:15:41 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_B(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_A == NULL)
		return ;
	if (!(*list)->begin_B)
	{
		(*list)->begin_B = (*list)->begin_A;
		(*list)->begin_A = (*list)->begin_A->next;
		(*list)->begin_B->next = NULL;
		(*list)->last_B = (*list)->begin_B;
	}
	else
	{
		tmp = (*list)->begin_A;
		(*list)->begin_A = (*list)->begin_A->next;
		tmp->next = (*list)->begin_B;
		(*list)->begin_B = tmp;
	}	
}

void	push_A(t_status_lists **list)
{
	t_init_list	*tmp;

	if ((*list)->begin_B == NULL)
		return ;
	if (!(*list)->begin_A)
	{
		(*list)->begin_A = (*list)->begin_B;
		(*list)->begin_B = (*list)->begin_B->next;
		(*list)->begin_A->next = NULL;
	}
	else
	{
		tmp = (*list)->begin_B;
		(*list)->begin_B = (*list)->begin_B->next;
		tmp->next = (*list)->begin_A;
		(*list)->begin_A = tmp;
	}	
}

void	swap_A(t_status_lists **list)
{
	t_init_list	*temp;

	if ((*list)->begin_A == NULL)
		return ;
	temp = (*list)->begin_A;
	(*list)->begin_A = (*list)->begin_A->next;
	temp->next = (*list)->begin_A->next;
	(*list)->begin_A->next = temp;
}

void	swap_B(t_status_lists **list)
{
	t_init_list	*temp;

	if ((*list)->begin_B == NULL)
		return ;
	temp = (*list)->begin_B;
	(*list)->begin_B = (*list)->begin_B->next;
	temp->next = (*list)->begin_B->next;
	(*list)->begin_B->next = temp;
}

void	swap_S(t_status_lists **list)
{
	t_init_list	*temp;

	if ((*list)->begin_B == NULL || (*list)->begin_A == NULL)
		return ;
	temp = (*list)->begin_A;
	(*list)->begin_A = (*list)->begin_A->next;
	temp->next = (*list)->begin_A->next;
	(*list)->begin_A->next = temp;
	temp = (*list)->begin_B;
	(*list)->begin_B = (*list)->begin_B->next;
	temp->next = (*list)->begin_B->next;
	(*list)->begin_B->next = temp;
}
