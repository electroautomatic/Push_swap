#include"push_swap.h"

int sort_or_not(t_init_list *list)
{
    while (list->next)
    {
        if(list->index_sort > list->next->index_sort)
        {
            return(0);
        }
        list = list->next;
    }
    return(1);
}

int list_size(t_status_lists **list)
{
    int size;
    t_init_list *tmp;
    
    size = 0;
    tmp = (*list)->begin_A;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    
    return(size);
}

void    index_sort(t_status_lists **list)
{
    int i;

    i = 1;    
    t_init_list *tmp;
    t_init_list *tmp_index;

    tmp = (*list)->begin_A;
    tmp_index = tmp;
    
    while (tmp_index)
    {
        while (tmp)
        {
            if(tmp_index->value > tmp->value)
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

void ft_free_list(t_status_lists **list)
{
    t_init_list *tmp;
    t_init_list *tmp_2;

    tmp = (*list)->begin_A;

    while (tmp)
    {
        tmp_2 = tmp->next;
        free(tmp);
        tmp = tmp_2;
    }    
}


