#include "push_swap.h"
void push(int arg, t_status_lists **list)
{
    t_init_list *tmp;

    if(arg)
    {
        if(!(*list)->begin_B)
        {
            (*list)->begin_B = (*list)->begin_A;
            (*list)->begin_A = (*list)->begin_A->next;
            (*list)->begin_B->next = NULL;
        }
        else
        {
            tmp = (*list)->begin_A;
            (*list)->begin_A = (*list)->begin_A->next;
            tmp->next = (*list)->begin_B;
            (*list)->begin_B = tmp;
        }
    }
    else
    {

    }
}

void    stack_inint(int argc, char **argv, t_status_lists **list)
{
    int i = 1;
    t_init_list *temp;

    while(i < argc)
    { 
        temp = malloc(sizeof(t_init_list));
        temp->value = atoi(argv[i]);
        temp->num = i;
        temp->next = NULL;
        if ((*list)->last_A)
        {
            (*list)->last_A->next = temp;
            (*list)->last_A = (*list)->last_A->next;
        }
        else
            (*list)->begin_A = (*list)->last_A = temp;
        i++;
    
    }
}

int main(int argc, char **argv)
{
    t_init_list *temp;
    t_status_lists *info_AB;
    //int i = 1;

    info_AB = malloc(sizeof(t_status_lists));
    info_AB->begin_A = NULL;
    info_AB->last_A = NULL;
    info_AB->begin_B = NULL;
    info_AB->last_B = NULL;
    stack_inint(argc, argv, &info_AB);
    
   
    push(0, &info_AB);
 //   push(0, &info_AB);
   
      temp = info_AB->begin_B;

     while (temp->next)
    {
        printf("%d - %d  \n", temp->num, temp->value);
        temp = temp->next;
    }
    printf("%d - %d  \n", temp->num, temp->value);
     temp = info_AB->begin_A;
    while (temp->next)
    {
        printf("%d - %d  \n", temp->num, temp->value);
        temp = temp->next;
    }
    printf("%d - %d  \n", temp->num, temp->value);
  
       
    return(0);
       
}