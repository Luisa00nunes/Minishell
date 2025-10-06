NAME = minishell

CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC= ms_split.c \
	ms_test.c \
	node_utils.c \

OBJS = $(SRC:.c=.o)

PRINTF = ~/42/printf/libftprintf.a

LIBFT = ~/42/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT) $(LIBFt_BONUS)
		$(CC) $(FLAGS) $(OBJS) -lreadline $(PRINTF) $(LIBFT) -o minishell

$(PRINTF):
		make -C ~/42/printf

$(LIBFT):
		make -C ~/42/libft

$(LIBFt_BONUS):
		make bonus -C ~/42/libft

clean:
	$(RM) $(OBJS)
	make clean -C ~/42/printf
	make clean -C ~/42/libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ~/42/printf
	make fclean -C ~/42/libft

re: fclean all
