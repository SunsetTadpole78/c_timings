NAME = c_timings.a

INCLUDE = include
SRC = src
OBJS = objs

FILES = timings.c	\
	utils.c

OFILES = $(FILES:%.c=$(OBJS)/%.o)

FLAGS = -Wall -Wextra -Werror
COMPILATOR = cc

all = $(NAME)

$(NAME): $(OFILES)
	@echo "Compiling..."
	ar cr $(NAME) $(OFILES)
	@echo "Compilation done."

$(LIBFTA):
	make -C $(LIBFT) bonus > /dev/null

clean:
	@echo "Remove objects files..."
	@rm -rf $(OFILES)
	@rm -rf $(OBJS)

fclean: clean
	@echo "Remove library file..."
	@rm -rf $(NAME)

$(OBJS)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	$(COMPILATOR) $(FLAGS) $< -c -o $@ -I $(INCLUDE)

re: fclean $(NAME)

.PHONY: all clean fclean re
