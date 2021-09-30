/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:04:38 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/27 16:36:48 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(int i, char **str)
{
	if (ft_atoi(str[i]) > 2147483648 || ft_atoi(str[i]) < -2147483647)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if ((str[i][0] == '+' && str[i][1] == '\0')
		|| (str[i][0] == '-' && str[i][1] == '\0')
		|| str[i][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	check_not_num(int i, char **str)
{
	int	flag;
	int	j;

	j = 0;
	flag = 0;
	while (str[i][j])
	{		
		if (str[i][j] == '+' || str[i][j] == '-')
		{	
			j++;
			flag++;
		}
		else if (str[i][j] < '0' || str[i][j] > '9' || flag > 1)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			j++;
	}
}

void	validation_args(int argc, char **argv)
{
	int		i;
	char	**str;

	str = argv;
	i = 1;
	while (i < argc)
	{
		check_not_num(i, str);
		check_int(i, str);
		i++;
	}
	if (argc <= 2)
	{
		exit(0);
	}		
}
