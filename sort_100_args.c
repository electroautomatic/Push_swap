#include "push_swap.h"

void    sort_100_args(t_status_lists **list)
{
    t_sort_inint *sort_init;
    t_init_list *tmp;
    
    sort_init = malloc(sizeof(t_sort_inint));
    sort_init->flag = 0;
    sort_init->max = 0;
    sort_init->mid =0;
    sort_init->next = 0;

    tmp = (*list)->begin_A;

}