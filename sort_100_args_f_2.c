/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_args_f_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:51:49 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/28 15:58:47 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_flag_one(t_status_lists **lst, t_init_list **t, t_sort_inint **s)
{
	(*t)->flag = -1;
	(*s)->next++;
	(*t) = (*t)->next;
	rotate_A(lst);
}

void	push_b_flag_two(t_status_lists **list, t_sort_inint **sort_inint)
{
	(*list)->begin_B->flag = -1;
	(*sort_inint)->next++;
	push_A(list);
	rotate_A(list);
}

void	push_b_flag_three(t_status_lists **list, t_sort_inint **sort_inint)
{
	(*list)->last_B->flag = -1;
	(*sort_inint)->next++;
	rotate_RB(list);
	push_A(list);
	rotate_A(list);
}

void	push_l_flags_B(t_status_lists **list, t_sort_inint *sort_inint)
{
	t_init_list	*tmp;
	int			flag;

	tmp = (*list)->begin_A;
	flag = tmp->flag;
	while (tmp->flag == flag)
	{
		if (tmp->index_sort == sort_inint->next)
			push_b_flag_one(list, &tmp, &sort_inint);
		else if ((*list)->begin_B != NULL
			&& (*list)->begin_B->index_sort == sort_inint->next)
			push_b_flag_two(list, &sort_inint);
		else if ((*list)->last_B != NULL && (*list)->last_B != (*list)->begin_B
			&& (*list)->last_B->index_sort == sort_inint->next)
			push_b_flag_three(list, &sort_inint);
		else if (tmp->flag == flag)
		{
			tmp = tmp->next;
			push_B(list);
		}
	}
}
