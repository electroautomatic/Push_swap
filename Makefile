CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: push_swap.c ft_atoi.o
	$(CC) $(CFLAGS) $^ -o $@