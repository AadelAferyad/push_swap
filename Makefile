NAME := push_swap
BONUS_NAME := checker
COMPILER := cc
FLAGS := -Wextra -Werror -Wall 
REMOVE := rm -f

src := main.c adjust_and_push.c improved_atoi.c index_fucntions.c list_util.c  more_index_func.c more_operations_util.c more_stack_utils.c operations_and_positions.c parser.c print_utils.c stack_util.c turky_sort.c 
src_libft := libft/ft_atoi.c libft/ft_puts.c libft/ft_putstr_fd.c libft/ft_putchar.c libft/ft_strdup.c libft/ft_substr.c libft/ft_isdigit.c libft/ft_strlen.c libft/ft_memcpy.c libft/ft_strlcpy.c libft/ft_split.c

src_bonus := checker.c bonus_util.c bonus_error.c adjust_and_push.c improved_atoi.c index_fucntions.c list_util.c  more_index_func.c more_operations_util.c more_stack_utils.c operations_and_positions.c parser.c print_utils.c stack_util.c turky_sort.c 

src_gnl := gnl/get_next_line.c gnl/get_next_line_utils.c

all: $(NAME)

$(NAME): $(src) $(src_libft) 
	$(COMPILER) $(FLAGS) -o $(NAME) $(src) $(src_libft)

bonus: $(src_bonus) $(src_libft) $(src_gnl)
	$(COMPILER) $(FLAGS) -o $(BONUS_NAME) $(src_bonus) $(src_libft) $(src_gnl)
clean:
	$(REMOVE) $(NAME)

fclean: clean
	$(REMOVE) $(NAME) $(BONUS_NAME)

re: fclean all
