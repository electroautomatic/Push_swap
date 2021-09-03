#include"push_swap.h"

void    push_B(t_status_lists **list)
{
    t_init_list *tmp;

    if(!(*list)->begin_B)
    {
        (*list)->begin_B = (*list)->begin_A;
        (*list)->begin_A = (*list)->begin_A->next;
        (*list)->begin_B->next = NULL;
        (*list)->last_B = (*list)->begin_B;
    }
    else
    {
        tmp = (*list)->begin_A;
        (*list)->begin_A = (*list)->begin_A->next;
        tmp->next = (*list)->begin_B;
        (*list)->begin_B = tmp;
        
    }
    write(1, "pb\n", 3);
}

void    push_A(t_status_lists **list)
{
    t_init_list *tmp;

    if(!(*list)->begin_A)
    {
        (*list)->begin_A = (*list)->begin_B;
        (*list)->begin_B = (*list)->begin_B->next;
        (*list)->begin_A->next = NULL;
    }
    else
    {
        tmp = (*list)->begin_B;
        (*list)->begin_B = (*list)->begin_B->next;
        tmp->next = (*list)->begin_A;
        (*list)->begin_A = tmp;
    }
    write(1, "pa\n", 3);
}

void    swap_A(t_status_lists **list)
{
    t_init_list *temp;
    
    temp = (*list)->begin_A;
    (*list)->begin_A = (*list)->begin_A->next;
    temp->next = (*list)->begin_A->next;
    (*list)->begin_A->next = temp;
    write(1, "sa\n", 3);
}

void    swap_B(t_status_lists **list)
{
    t_init_list *temp;
    
    temp = (*list)->begin_B;
    (*list)->begin_B = (*list)->begin_B->next;
    temp->next = (*list)->begin_B->next;
    (*list)->begin_B->next = temp;
    write(1, "sb\n", 3);
}

void    swap_S(t_status_lists **list)
{
    t_init_list *temp;
    
    temp = (*list)->begin_A;
    (*list)->begin_A = (*list)->begin_A->next;
    temp->next = (*list)->begin_A->next;
    (*list)->begin_A->next = temp;
   
    temp = (*list)->begin_B;
    (*list)->begin_B = (*list)->begin_B->next;
    temp->next = (*list)->begin_B->next;
    (*list)->begin_B->next = temp;
    write(1, "ss\n", 3);
}

void    rotate_A(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_A;
    (*list)->begin_A = (*list)->begin_A->next;
    (*list)->last_A->next = tmp;
    (*list)->last_A = tmp;
    (*list)->last_A->next = NULL;
    write(1, "ra\n", 3);    
}

void    rotate_B(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_B;
    (*list)->begin_B = (*list)->begin_B->next;
    (*list)->last_B->next = tmp;
    (*list)->last_B = tmp;
    (*list)->last_B->next = NULL;
    write(1, "rb\n", 3);
}

void    rotate_R(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_A;
    (*list)->begin_A = (*list)->begin_A->next;
    (*list)->last_A->next = tmp;
    (*list)->last_A = tmp;
    (*list)->last_A->next = NULL;

    tmp = (*list)->begin_B;
    (*list)->begin_B = (*list)->begin_B->next;
    (*list)->last_B->next = tmp;
    (*list)->last_B = tmp;
    (*list)->last_B->next = NULL;
    write(1, "rr\n", 3);
}

void    rotate_RA(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_A;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    (*list)->last_A->next = (*list)->begin_A;

    (*list)->begin_A = (*list)->last_A;
    (*list)->last_A = tmp;
    write(1, "rra\n", 4);
}

void    rotate_RB(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_B;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    (*list)->last_B->next = (*list)->begin_B;

    (*list)->begin_B = (*list)->last_B;
    (*list)->last_B = tmp;
    write(1, "rrb\n", 4);
}

void    rotate_RR(t_status_lists **list)
{
    t_init_list *tmp;

    tmp = (*list)->begin_A;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    (*list)->last_A->next = (*list)->begin_A;

    (*list)->begin_A = (*list)->last_A;
    (*list)->last_A = tmp;

    tmp = NULL;
    tmp = (*list)->begin_B;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    (*list)->last_B->next = (*list)->begin_B;

    (*list)->begin_B = (*list)->last_B;
    (*list)->last_B = tmp;
    write(1, "rrr\n", 4);
}