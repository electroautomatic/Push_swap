/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:14:12 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/28 18:41:35 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	rd = 1;
	i = 0;
	ch = 0;
	buffer = malloc(100000);
	*line = buffer;
	while ((rd > 0) && (ch != '\n'))
	{
		rd = read(0, &ch, 1);
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return (rd);
}
