/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:25:23 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 14:15:59 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_or_not(t_init_list *list)
{
	while (list->next)
	{
		if (list->index_sort > list->next->index_sort)
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int	list_size(t_status_lists **list)
{
	t_init_list	*tmp;
	int			size;

	size = 0;
	tmp = (*list)->begin_A;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	index_sort(t_status_lists **list)
{
	t_init_list	*tmp;
	t_init_list	*tmp_index;
	int			i;

	i = 1;
	tmp = (*list)->begin_A;
	tmp_index = tmp;
	while (tmp_index)
	{
		while (tmp)
		{
			if (tmp_index->value > tmp->value)
			{
				i++;
			}
			tmp = tmp->next;
		}
		tmp_index->index_sort = i;
		tmp = (*list)->begin_A;
		tmp_index = tmp_index->next;
		i = 1;
	}
}

void	ft_free_list(t_status_lists **list)
{
	t_init_list	*tmp;
	t_init_list	*tmp_2;

	tmp = (*list)->begin_A;
	while (tmp)
	{
		tmp_2 = tmp->next;
		free(tmp);
		tmp = tmp_2;
	}
}

void	stack_inint(int argc, char **argv, t_status_lists **list)
{
	t_init_list	*temp;
	int			i;

	i = 1;
	while (i < argc)
	{
		temp = malloc(sizeof(t_init_list));
		temp->value = atoi(argv[i]);
		temp->num = i;
		temp->flag = 0;
		temp->next = NULL;
		if ((*list)->last_A)
		{
			(*list)->last_A->next = temp;
			(*list)->last_A = (*list)->last_A->next;
		}
		else
		{
			(*list)->begin_A = temp;
			(*list)->last_A = (*list)->begin_A;
		}
		i++;
	}
}
