NAME = push_swap
SRCS = $(wildcard ./srcs/*.c)
OBJS_DIR = ./objs
OBJS = $(SRCS:./srcs/%.c=$(OBJS_DIR)/%.o)
LIBFT = ./Libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

GREEN = \033[0;92m
BLUE = \033[0;94m

all: makelibs $(NAME)

makelibs:
	@make -C ./Libft
	@echo "$(BLUE)**libft compiled"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: ./srcs/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap compiled"

clean:
	$(RM) $(OBJS_DIR)
	@make clean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./Libft

re: fclean all
