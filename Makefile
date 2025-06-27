NAME = c_timings.a

INCLUDE = include
SRC = src
OBJS = objs

FILES =	activation.c			\
		reporter.c				\
		sessions.c				\
		thread_data.c			\
		timings.c				\
		libft/ft_ftoa.c			\
		libft/ft_ltoa.c			\
		libft/ft_putnbr_fd.c	\
		libft/ft_putllnbr_fd.c	\
		libft/ft_strdup.c		\
		libft/ft_strlen.c		\
		libft/ft_timestamp.c	\
		libft/ft_timestamp_us.c	\
		libft/ft_log.c			\
		libft/ft_llog.c			\
		libft/ft_round.c		\
		libft/ft_strjoin.c		\
		libft/ft_strncmp.c		\
		libft/ft_pathjoin.c

OFILES = $(FILES:%.c=$(OBJS)/%.o)

FLAGS = -Wall -Wextra -Werror
COMPILATOR = cc

TESTS_DIR = tests
TEST_FILE = $(TESTS_DIR)/test.c
TEST = test

all = $(NAME)

$(NAME): $(OFILES)
	@echo "Compiling..."
	ar cr $(NAME) $(OFILES)
	@echo "Compilation done."

clean:
	@echo "Remove objects files..."
	@rm -rf $(OFILES)
	@rm -rf $(OBJS)

fclean: clean
	@echo "Remove library file..."
	@rm -f $(NAME)
	@rm -f $(TEST)

$(OBJS)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	$(COMPILATOR) $(FLAGS) $< -c -o $@ -I $(INCLUDE) -g

re: fclean $(NAME)

test: re
	cc $(FLAGS) -g $(TEST_FILE) $(NAME) -I $(INCLUDE) -o $(TEST)

.PHONY: all clean fclean re
