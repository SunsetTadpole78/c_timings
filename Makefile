NAME = c_timings.a

INCLUDE = include
SRC = src
OBJS = objs

FILES =	activation.c			\
		reporter.c				\
		sessions.c				\
		timings.c				\
		libft/ft_ftoa.c			\
		libft/ft_ltoa.c			\
		libft/ft_putnbr_fd.c	\
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
	@rm -rf $(NAME)

$(OBJS)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	$(COMPILATOR) $(FLAGS) $< -c -o $@ -I $(INCLUDE) -g

re: fclean $(NAME)

.PHONY: all clean fclean re
