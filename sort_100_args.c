/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:14:07 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 16:47:05 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_low_mid_B(t_status_lists **list, t_sort_inint *sort_inint)
{
	t_init_list	*tmp;
	int			count;

	count = list_size_new((*list)->begin_A);
	(*list)->max_index_list_A = (*list)->last_A->num;
	sort_inint->max = (*list)->max_index_list_A;
	sort_inint->mid = (sort_inint->max) / 2;
	tmp = (*list)->begin_A;
	while (count)
	{
		if (tmp->index_sort <= sort_inint->mid)
		{
			tmp = tmp->next;
			push_B(list);
		}
		else
		{
			tmp = tmp->next;
			rotate_A(list);
		}
		count--;
	}
}

void	revers_rotate(int count, t_status_lists	**list, t_sort_inint *sort_in)
{
	while (count)
	{
		if ((*list)->begin_B->index_sort != sort_in->next)
		{
			rotate_RR(list);
			count--;
		}
		else
		{
			rotate_RA(list);
			count--;
		}
	}
}

void	push_low_mid_B2(t_status_lists **list, t_sort_inint *sort_inint)
{
	t_init_list	*tmp;
	int			count;

	count = 0;
	sort_inint->max = (*list)->max_index_list_A;
	sort_inint->mid = (sort_inint->max - sort_inint->next)
		/ 2 + sort_inint->next;
	tmp = (*list)->begin_A;
	while (tmp->flag == 0)
	{
		if (tmp->index_sort <= sort_inint->mid)
		{
			tmp = tmp->next;
			push_B(list);
		}
		else
		{
			tmp = tmp->next;
			rotate_A(list);
			count++;
		}		
	}
	revers_rotate(count, list, sort_inint);
}

void	sort_100_args(t_status_lists **list)
{
	t_sort_inint	*sort_init;

	sort_init = malloc(sizeof(t_sort_inint));
	sort_init->max = 0;
	sort_init->mid = 0;
	sort_init->next = 1;
	(*list)->flag_group = 500;
	push_low_mid_B(list, sort_init);
	while (!sort_or_not((*list)->begin_A) || (*list)->begin_B != NULL)
	{
		if (!(*list)->begin_B && ((*list)->begin_A->flag == 0))
			push_low_mid_B2(list, sort_init);
		else if (!(*list)->begin_B)
			push_l_flags_B(list, sort_init);
		while ((*list)->begin_B)
		{
			push_mid_A(list, sort_init);
			(*list)->flag_group--;
		}
	}
	free(sort_init);
}
