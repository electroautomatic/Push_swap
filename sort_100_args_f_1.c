/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_args_f_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:43:38 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/28 15:50:30 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a_one(int c, t_status_lists **l, t_init_list **t, t_sort_inint **s)
{
	(*t)->flag = -1;
	(*s)->next++;
	(*t) = (*t)->next;
	push_A(l);
	rotate_A(l);
	c--;
	return (c);
}

int	push_a_two(int c, t_status_lists **l, t_init_list **t, t_sort_inint **s)
{
	if ((*t)->index_sort > (*s)->mid)
	{
		(*t)->flag = (*l)->flag_group;
		(*t) = (*t)->next;
		push_A(l);
		c--;
	}
	else
	{
		(*t) = (*t)->next;
		if (*t)
			rotate_B(l);
		c--;
	}
	return (c);
}

void	push_a_three(t_status_lists **list, t_sort_inint **sort_inint)
{
	(*sort_inint)->next++;
	swap_A(list);
	rotate_A(list);
}

void	push_mid_A(t_status_lists **list, t_sort_inint *sort_inint)
{
	t_init_list	*tmp;
	int			count;

	count = list_size_new((*list)->begin_B);
	sort_inint->max = ft_list_max_num((*list)->begin_B);
	sort_inint->mid = (sort_inint->max - sort_inint->next)
		/ 2 + sort_inint->next;
	tmp = (*list)->begin_B;
	while (count)
	{
		if (tmp->index_sort == sort_inint->next)
			count = push_a_one(count, list, &tmp, &sort_inint);
		else if ((*list)->begin_A->index_sort == sort_inint->next)
		{
			sort_inint->next++;
			rotate_A(list);
		}
		else if ((*list)->begin_A->next->index_sort == sort_inint->next)
			push_a_three(list, &sort_inint);
		else
			count = push_a_two(count, list, &tmp, &sort_inint);
	}
}
