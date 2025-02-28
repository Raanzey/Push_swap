NAME = push_swap

CFLAGS = cc -Wall -Wextra -Werror

SOURCES = push_swap.c push_swap_utils.c control.c libft_utils.c list_op.c turk_sorter.c turk_sorter_utils.c push_b_op.c push_a_op.c

LIBFT = libft/libft.a



all: $(NAME)


$(NAME): $(SOURCES)
	make -C ./libft -s
	$(CFLAGS) -g -o $(NAME) $(SOURCES) $(LIBFT)

clean:
	make clean -C ./libft -s

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re