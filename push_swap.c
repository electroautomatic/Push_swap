/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:30:46 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/26 19:05:22 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_status_lists	*info_AB;

	validation_args(argc, argv);
	info_AB = malloc(sizeof(t_status_lists));
	info_AB->begin_A = NULL;
	info_AB->last_A = NULL;
	info_AB->begin_B = NULL;
	info_AB->last_B = NULL;
	stack_inint(argc, argv, &info_AB);
	chek_double(info_AB->begin_A);
	index_sort(&info_AB);
	if (sort_or_not(info_AB->begin_A))
		exit(0);
	if (argc == 3)
		rotate_A(&info_AB);
	else if (argc == 4)
		sort_3_args(&info_AB);
	else if (argc == 5)
		sort_4_args(&info_AB);
	else if (argc == 6)
		sort_5_args(&info_AB);
	else
		sort_100_args(&info_AB);
	ft_free_list(&info_AB);
	free(info_AB);
	return (0);
}
