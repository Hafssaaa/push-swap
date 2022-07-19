CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=push_swap

SRCS=	src/main.c src/push_a.c src/utils.c src/lis.c \
		src/stack.c src/push_b.c actions/px.c \
		src/mini_lib.c src/sort.c src/split.c \
		src/utils2.c \
		actions/rrx.c actions/rx.c\
		actions/sx.c \
		src/utils3.c src/utils4.c\


INC = inc/push_swap.h

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(INC)
		CC $(CFLAGS) $(OBJCTS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJCTS)

fclean: clean
		rm -f $(NAME)
		
re: fclean all	
