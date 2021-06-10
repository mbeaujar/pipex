NAME=pipex
CC=clang
CFLAGS= -Wall -Wextra -Werror
RM=rm -f
HEADER=include

SRCS = source/child.c \
	source/ft_split.c \
	source/main.c \
	source/parsing.c \
	source/get_next_line.c \
	source/get_next_line_utils.c \
	source/ft_strcmp.c \
	source/ft_strjoin.c \
	source/put.c \
	source/bonus.c 

all : $(NAME)

bonus : $(OBJS)
	@$(CC) $(CFLAGS) -D BONUS=1 -I$(HEADER) $(SRCS) -o $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I$(HEADER) $(SRCS) -o $(NAME)


clean :
	@$(RM) $(NAME)

fclean : clean

re : fclean all


