NAME=pipex
CC=clang
CFLAGS= -Wall -Wextra -Werror
RM=rm -f

SRCS = child.c \
	ft_split.c \
	main.c \
	parsing.c 

OBJS = ${SRCS:.c=.o}

%.o : %.c 
	@$(CC) $(CFLAGS) $< -c -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(OBJS)

re : fclean all


