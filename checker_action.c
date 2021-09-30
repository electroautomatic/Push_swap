/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:15:12 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 17:16:10 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_part_one(char *str, t_status_lists **list, int *flag)
{
	if (str[0] == 'p' && str [1] == 'b' && str[2] == '\n')
		push_B(list);
	else if (str[0] == 'p' && str [1] == 'a' && str[2] == '\n')
		push_A(list);
	else if (str[0] == 's' && str [1] == 'a' && str[2] == '\n')
		swap_A(list);
	else if (str[0] == 's' && str [1] == 'b' && str[2] == '\n')
		swap_B(list);
	else if (str[0] == 's' && str [1] == 's' && str[2] == '\n')
		swap_S(list);
	else
		*flag = 1;
}

void	action_part_two(char *str, t_status_lists **list, int *flag)
{
	if (str[0] == 'r' && str [1] == 'a' && str[2] == '\n')
		rotate_A(list);
	else if (str[0] == 'r' && str [1] == 'b' && str[2] == '\n')
		rotate_B(list);
	else if (str[0] == 'r' && str [1] == 'r' && str[2] == '\n')
		rotate_R(list);
	else if (str[0] == 'r' && str [1] == 'r' && str [2] == 'a'
		&& str[3] == '\n')
		rotate_RA(list);
	else if (str[0] == 'r' && str [1] == 'r' && str [2] == 'b'
		&& str[3] == '\n')
		rotate_RB(list);
	else if (str[0] == 'r' && str [1] == 'r' && str [2] == 'r'
		&& str[3] == '\n')
		rotate_RR(list);
	else if (*flag == 1)
	{	
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	action(char *str, t_status_lists **list)
{
	int	flag;

	flag = 0;
	action_part_one(str, list, &flag);
	action_part_two(str, list, &flag);
	flag = 0;
}
