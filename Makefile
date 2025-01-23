NAME = philo
SRCS = $(shell find -type f -name "*.c")
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	   cc $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re