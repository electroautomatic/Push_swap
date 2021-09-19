

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRCMODULES_A = push_swap.c\
			   ft_atoi.c\
			   operations.c\
			   sort_3_args.c\
			   sort_5_args.c\
			   sort_100_args.c\
			   functions.c
			   
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