#include "push_swap.h"

int list_size_new(t_init_list *list)
{
    int size;
    t_init_list *tmp;
    
    size = 0;
    tmp = list;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    
    return(size);
}

void    push_low_mid_B(t_status_lists **list, t_sort_inint *sort_inint) //запускаем 1 раз вначале сортировки.
{
    t_init_list *tmp;
    int  count;

    count = list_size_new((*list)->begin_A);
    (*list)->max_index_list_A = (*list)->last_A->num;
    sort_inint->max = (*list)->max_index_list_A;
    sort_inint->mid = (sort_inint->max) / 2 + sort_inint->next;

    tmp = (*list)->begin_A;

    while (count)
    {
        if (tmp->index_sort <= sort_inint->mid)
        {
            tmp = tmp->next;
            push_B(list);
        }
        else
        {
            tmp = tmp->next;
            rotate_A(list);
        }
        count--;
    }
}

void    push_low_mid_B2(t_status_lists **list, t_sort_inint *sort_inint) // запускаем каждый раз когда в стеке А остаются не отсортированные элементы с флагом 0.
{
    t_init_list *tmp;
    int  count;

    count = 0;
    sort_inint->max = (*list)->max_index_list_A;
    sort_inint->mid = (sort_inint->max - sort_inint->next) / 2 + sort_inint->next;

    tmp = (*list)->begin_A;

    while (tmp->flag == 0)
    {
        if (tmp->index_sort <= sort_inint->mid)
        {
            tmp = tmp->next;
            push_B(list);
        }
        else
        {
            tmp = tmp->next;
            rotate_A(list);
            count++;
        }
        
    }
    while (count)
    {
        rotate_RA(list);
        count--;
    }
    
}

void    push_high_mid_A(t_status_lists **list, t_sort_inint *sort_inint)
{
    t_init_list *tmp;
    int  count;
    
    
    count = list_size_new((*list)->begin_B);
    sort_inint->max = sort_inint->mid;
    sort_inint->mid = (sort_inint->max - sort_inint->next) / 2 + sort_inint->next;

    tmp = (*list)->begin_B;

    while (count)
    {
        if (tmp->index_sort == sort_inint->next)
        {
            tmp->flag = -1;
            sort_inint->next++;
            tmp = tmp->next;
            push_A(list);
            rotate_A(list);
            //break;
        }
        else if (tmp->next != NULL && tmp->next->index_sort == sort_inint->next)
        {
            tmp = tmp->next;
            swap_B(list);
            tmp->flag = -1;
            sort_inint->next++;
            tmp = tmp->next;
            push_A(list);
            rotate_A(list);
            //break;
        }
        else if ((*list)->begin_B != NULL && (*list)->last_B != (*list)->begin_B && (*list)->last_B->index_sort == sort_inint->next)
        {
            tmp = (*list)->last_B;
            rotate_RB(list);
            tmp->flag = -1;
            sort_inint->next++;
            tmp = tmp->next;
            push_A(list);
            rotate_A(list);
            //break;
        }
        
        else if ((*list)->begin_A->index_sort == sort_inint->next)
        {
            sort_inint->next++;
            rotate_A(list);
            //break;
        }
        else if ((*list)->begin_A->next->index_sort == sort_inint->next)
        {
            sort_inint->next++;
            swap_A(list);
            rotate_A(list);
            //break;
        }
        else
        {
            if (tmp->index_sort > sort_inint->mid)
            {
                tmp->flag++;
                tmp = tmp->next;
                push_A(list);
            }
            else
            {
                tmp = tmp->next;
                if (tmp)
                rotate_B(list);
            }
        }
        count--;
    }

}

void    push_list_flags_B(t_status_lists **list, t_sort_inint *sort_inint)
{
    t_init_list *tmp;
 //   int  count;
    int flag;

 //   count = list_size_new((*list)->begin_A);
    tmp = (*list)->begin_A;
    flag = tmp->flag;

    while (tmp->flag == flag)
    {
        if (tmp->index_sort == sort_inint->next)
        {
            tmp->flag = -1;
            sort_inint->next++;
            tmp = tmp->next;
            rotate_A(list);
 //           count--;
        }
        else if ((*list)->begin_B != NULL && (*list)->begin_B->index_sort == sort_inint->next)
        {
            (*list)->begin_B->flag = -1;
            sort_inint->next++;
            push_A(list);
            rotate_A(list);
            //break;
        }
  /*      else if ((*list)->last_B != NULL && (*list)->begin_B->next != NULL && (*list)->begin_B->next->index_sort == sort_inint->next)
        {
            (*list)->begin_B->next->flag = -1;
            sort_inint->next++;
            swap_B(list);
            push_A(list);
            rotate_A(list);
            //break;
        }
*/        else if ((*list)->last_B != NULL && (*list)->last_B != (*list)->begin_B && (*list)->last_B->index_sort == sort_inint->next)
        {
            (*list)->last_B->flag = -1;
            sort_inint->next++;
            rotate_RB(list);
            push_A(list);
            rotate_A(list);
            //break;
        }
        else if (tmp->flag == flag)
        {
            tmp = tmp->next;
            push_B(list);
        }
 //       count--;
    }
    

}

void    sort_100_args(t_status_lists **list)
{
    t_sort_inint *sort_init;
    
    
    sort_init = malloc(sizeof(t_sort_inint));
    sort_init->max = 0;
    sort_init->mid =0;
    sort_init->next = 1;
    //(*list)->flag_group = 1;
    
    push_low_mid_B(list, sort_init);
    
    while(!sort_or_not((*list)->begin_A))
    {
        
        if (!(*list)->begin_B && ((*list)->begin_A->flag == 0))
            push_low_mid_B2(list, sort_init);
        else if (!(*list)->begin_B)
            push_list_flags_B(list, sort_init);
        while ((*list)->begin_B)
        {
            push_high_mid_A(list, sort_init);
            //(*list)->flag_group++;
            //printf("flag - %d\n", (*list)->begin_A->flag);
        }
    }
    

 /*   push_low_mid_B(list, sort_init);
    push_high_mid_A(list, sort_init);
    push_high_mid_A(list, sort_init);
    push_high_mid_A(list, sort_init);
    push_list_flags_B(list);
    push_high_mid_A(list, sort_init);
    push_list_flags_B(list);
    push_high_mid_A(list, sort_init);
    push_high_mid_A(list, sort_init);
    push_list_flags_B(list);
    push_high_mid_A(list, sort_init);
    push_list_flags_B(list);
    push_high_mid_A(list, sort_init);
    push_list_flags_B(list);
    push_high_mid_A(list, sort_init);
    push_high_mid_A(list, sort_init);
*/
}