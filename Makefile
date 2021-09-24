

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRCMODULES_A = push_swap.c\
			   ft_atoi.c\
			   operations_1.c operations_2.c operations_3.c\
			   sort_3_args.c\
			   sort_4_args.c\
			   sort_5_args.c\
			   sort_100_args.c\
			   functions_1.c functions_2.c
			   
OBJMODULES_A = $(patsubst %.c,%.o,$(SRCMODULES_A))

all	: push_swap

push_swap: $(OBJMODULES_A)
		$(CC) $(CFLAGS) $(OBJMODULES_A) -o push_swap

clean :
	@rm -rf $(OBJMODULES_A)

fclean : clean
	@rm -rf push_swap

re : fclean all

.PHONY : all clean fclean re