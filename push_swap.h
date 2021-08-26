#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //  удалить после!

typedef struct s_list
{
    int value;
    int num;
    struct s_list *next;
    struct s_list *prev;
}   t_init_list;

typedef struct item_stat
{
    t_init_list *begin_A;
    t_init_list *last_A;
    t_init_list *begin_B;
    t_init_list *last_B;    
}   t_status_lists;

int ft_atoi(const char *str);

#endif