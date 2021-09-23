/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:21:35 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/23 17:24:13 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size_new(t_init_list *list)
{
	int			size;
	t_init_list	*tmp;

	size = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int	ft_list_max_num(t_init_list *list)
{
	int			max_num;
	t_init_list	*tmp;

	max_num = 0;
	tmp = list;
	while (tmp)
	{
		if (max_num < tmp->index_sort)
			max_num = tmp->index_sort;
		tmp = tmp->next;
	}
	return (max_num);
}
