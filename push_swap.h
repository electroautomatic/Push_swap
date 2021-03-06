/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:13:40 by mbalman           #+#    #+#             */
/*   Updated: 2021/09/29 17:17:33 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //  удалить после!

typedef struct s_list
{
	int				value;
	int				num;
	int				index_sort;
	struct s_list	*next;
	int				flag;
}	t_init_list;

typedef struct item_stat
{
	t_init_list	*begin_A;
	t_init_list	*last_A;
	t_init_list	*begin_B;
	t_init_list	*last_B;
	int			max_index_list_A;
	int			flag_group;
}	t_status_lists;

typedef struct s_sort_init
{
	int	next;
	int	mid;
	int	max;
}	t_sort_inint;

long long int	ft_atoi(const char *str);
int				sort_or_not(t_init_list *list);
int				list_size(t_status_lists **list);
void			index_sort(t_status_lists **list);
void			push_A(t_status_lists **list);
void			push_B(t_status_lists **list);
void			swap_A(t_status_lists **list);
void			swap_B(t_status_lists **list);
void			swap_S(t_status_lists **list);
void			rotate_A(t_status_lists **list);
void			rotate_B(t_status_lists **list);
void			rotate_R(t_status_lists **list);
void			rotate_RA(t_status_lists **list);
void			rotate_RB(t_status_lists **list);
void			rotate_RR(t_status_lists **list);

void			sort_3_args(t_status_lists **list);
void			sort_4_args(t_status_lists **list);
void			sort_5_args(t_status_lists **list);
void			sort_100_args(t_status_lists **list);
void			push_mid_A(t_status_lists **list, t_sort_inint *sort_inint);
void			push_l_flags_B(t_status_lists **list, t_sort_inint *sort_inint);

void			ft_free_list(t_status_lists **list);
int				list_size_new(t_init_list *list);
int				ft_list_max_num(t_init_list *list);
void			chek_double(t_init_list *list);

void			validation_args(int argc, char **argv);
void			check_int(int i, char **str);
void			check_not_num(int i, char **str);
int				get_next_line(char **line);

void			stack_inint(int argc, char **argv, t_status_lists **list);
void			action(char *str, t_status_lists **list);

#endif
