/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:21:35 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/27 16:05:20 by mbalman          ###   ########.fr       */
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

void	chek_double(t_init_list *list)
{
	int			value;
	int			value_num;
	t_init_list	*tmp1;
	t_init_list	*tmp2;

	tmp1 = list;
	tmp2 = list;
	while (tmp1)
	{
		value = tmp1->value;
		value_num = tmp1->num;
		while (tmp2)
		{
			if (tmp2->value == value && tmp2->num != value_num)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			tmp2 = tmp2 ->next;
		}
		tmp2 = list;
		tmp1 = tmp1->next;
	}
}
