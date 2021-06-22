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
	source/bonus.c \
	source/search_path.c


OBJS = ${SRCS:.c=.o}

%.o : %.c 
	@$(CC) $(CFLAGS) -I$(HEADER) $< -c -o $@

all : $(NAME)

bonus : $(OBJS)
	@$(CC) $(CFLAGS) -D BONUS=1 -I$(HEADER) $(OBJS) -o $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I$(HEADER) $(OBJS) -o $(NAME)


clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

