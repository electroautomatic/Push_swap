

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRCMODULES_A = push_swap.c\
			   ft_atoi.c\
			   operations_1.c operations_2.c operations_3.c\
			   sort_3_args.c\
			   sort_4_args.c\
			   sort_5_args.c\
			   sort_100_args.c sort_100_args_f_1.c sort_100_args_f_2.c\
			   functions_1.c functions_2.c functions_3.c

SRCMODULES_B = checker.c\
			   ft_atoi.c\
			   operations_1_checker.c operations_2_checker.c operations_3_checker.c\
			   functions_1.c functions_2.c functions_3.c\
			   get_next_line.c\
			   checker_action.c	   

OBJMODULES_A = $(patsubst %.c,%.o,$(SRCMODULES_A))
OBJMODULES_B = $(patsubst %.c,%.o,$(SRCMODULES_B))

push_swap: $(OBJMODULES_A) push_swap.h
		$(CC) $(CFLAGS) $(OBJMODULES_A) -o push_swap

checker: $(OBJMODULES_B)
		$(CC) $(CFLAGS) $(OBJMODULES_B) -o checker

clean :
	@rm -rf $(OBJMODULES_A) $(OBJMODULES_B)

fclean : clean
	@rm -rf push_swap checker

re : fclean all

.PHONY : all clean fclean re