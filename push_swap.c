#include "push_swap.h"



void    stack_inint(int argc, char **argv, t_status_lists **list)
{
    int i = 1;
    t_init_list *temp;

    while(i < argc)
    { 
        temp = malloc(sizeof(t_init_list));
        temp->value = atoi(argv[i]);
        temp->num = i;
        temp->flag = 0;
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
 //   t_init_list *temp;
    t_status_lists *info_AB;
    
    info_AB = malloc(sizeof(t_status_lists));
    info_AB->begin_A = NULL;
    info_AB->last_A = NULL;
    info_AB->begin_B = NULL;
    info_AB->last_B = NULL;
    
    stack_inint(argc, argv, &info_AB);
    index_sort(&info_AB);
   
    //push_B(&info_AB);
    //push_B(&info_AB);
    //push_B(&info_AB);
       
 // Проверка прямой команды -------------------------- 
        
 /*   printf("Stack A\n");
    temp = info_AB->begin_A;
    while (temp->next)
    {
        printf("%d - %d  \n", temp->num, temp->value);
        temp = temp->next;
    }
    printf("%d - %d  \n", temp->num, temp->value);
// Проверка реверсной команды--------------------------  
    
    rotate_RR(&info_AB);
       
    printf("Stack B\n");
    temp = info_AB->begin_B; 
    while (temp->next)
    {
        printf("%d - %d  \n", temp->num, temp->value);
        temp = temp->next;
    }
    printf("%d - %d  \n", temp->num, temp->value);
    
 */       
    //sort_3_args(&info_AB);

    //sort_5_args(&info_AB);
    sort_100_args(&info_AB);

 ///------------------------------------------------------
 /*   printf("Stack A\n");
    temp = info_AB->begin_A;
    while (temp)
    {
        printf("%d - %d  \n", temp->value, temp->index_sort);
        temp = temp->next;
    }

    printf("Stack B\n");
    temp = info_AB->begin_B;
    while (temp)
    {
        printf("%d - %d  \n", temp->value, temp->index_sort);
        temp = temp->next;
    }
*/        
    return(0);
       
}