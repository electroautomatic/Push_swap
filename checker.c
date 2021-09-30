/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:20:28 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 17:15:47 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list(t_status_lists **list)
{
	if (sort_or_not((*list)->begin_A))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	error_zerro(char *str)
{
	if (str[0] != '\0')
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_status_lists	*info_AB;
	char			*str;

	str = NULL;
	validation_args(argc, argv);
	info_AB = malloc(sizeof(t_status_lists));
	info_AB->begin_A = NULL;
	info_AB->last_A = NULL;
	info_AB->begin_B = NULL;
	info_AB->last_B = NULL;
	stack_inint(argc, argv, &info_AB);
	chek_double(info_AB->begin_A);
	index_sort(&info_AB);
	while (get_next_line(&str))
	{	
		action(str, &info_AB);
		free(str);
	}
	error_zerro(str);
	check_list(&info_AB);
	ft_free_list(&info_AB);
	free(str);
	free(info_AB);
	return (0);
}
