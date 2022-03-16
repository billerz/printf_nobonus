DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[38;5;222m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
ORANGE = \033[38;5;166m

SRCS = ft_printf.c \
		ft_printf_utils_general.c \
		ft_printf_utils_unsigned.c \
		ft_printf_utils_hex.c \
		ft_printf_utils_ptr.c

OBJS = $(SRCS:.c=.o)

NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)Adding function to library...$(NORMAL)"
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@rm -rf $(OBJS)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o: %.c
		@echo "$(ORANGE)Compiling: $(YELLOW)$<$(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c $< -o $@ -Ilibft -I.

clean:
			@rm -rf $(OBJS)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT)/libft.a
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			norminette $(SRC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
