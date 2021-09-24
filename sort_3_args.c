/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:27:13 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/24 17:37:04 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa_rra(t_status_lists **list)
{
	swap_A(list);
	rotate_RA(list);
}

void	rra_sa(t_status_lists **list)
{
	rotate_RA(list);
	swap_A(list);
}

void	sort_3_args(t_status_lists **list)
{
	int	f_val;
	int	s_val;
	int	t_val;

	f_val = (*list)->begin_A->index_sort;
	s_val = (*list)->begin_A->next->index_sort;
	t_val = (*list)->last_A->index_sort;
	if (!sort_or_not((*list)->begin_A))
	{
		if ((f_val > s_val) && (f_val < t_val) && (t_val > s_val))
			swap_A(list);
		else if ((f_val > s_val) && (f_val > t_val) && (t_val < s_val))
			sa_rra(list);
		else if ((f_val > s_val) && (f_val > t_val) && (t_val > s_val))
			rotate_A(list);
		else if ((f_val < s_val) && (f_val < t_val) && (t_val < s_val))
			rra_sa(list);
		else if ((f_val < s_val) && (f_val > t_val) && (t_val < s_val))
			rotate_RA(list);
	}
}
