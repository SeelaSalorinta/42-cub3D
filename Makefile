NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT_SRCS = $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_isdigit.c \
			 $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isascii.c \
			 $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_strlen.c \
			 $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_bzero.c \
			 $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c \
			 $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strlcat.c \
			 $(LIBFT_DIR)/ft_toupper.c $(LIBFT_DIR)/ft_tolower.c \
			 $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strrchr.c \
			 $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_memchr.c \
			 $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_strnstr.c \
			 $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_calloc.c \
			 $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_substr.c \
			 $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strtrim.c \
			 $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_itoa.c \
			 $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_striteri.c \
			 $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putstr_fd.c \
			 $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c \
			 $(LIBFT_DIR)/ft_lstnew_bonus.c $(LIBFT_DIR)/ft_lstadd_front_bonus.c \
			 $(LIBFT_DIR)/ft_lstsize_bonus.c $(LIBFT_DIR)/ft_lstlast_bonus.c \
			 $(LIBFT_DIR)/ft_lstadd_back_bonus.c $(LIBFT_DIR)/ft_lstdelone_bonus.c \
			 $(LIBFT_DIR)/ft_lstclear_bonus.c $(LIBFT_DIR)/ft_lstiter_bonus.c \
			 $(LIBFT_DIR)/ft_lstmap_bonus.c $(LIBFT_DIR)/get_next_line.c \
			 $(LIBFT_DIR)/get_next_line_utils.c $(LIBFT_DIR)/get_next_line_bonus.c \
			 $(LIBFT_DIR)/get_next_line_utils_bonus.c $(LIBFT_DIR)/ft_printf.c \
			 $(LIBFT_DIR)/ft_print_char.c $(LIBFT_DIR)/ft_print_s.c \
			 $(LIBFT_DIR)/ft_print_nbr.c $(LIBFT_DIR)/ft_print_hex.c \
			 $(LIBFT_DIR)/ft_print_ptr.c $(LIBFT_DIR)/ft_print_unsig.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git

INCLUDES = -I./ -I$(MINILIBX_DIR) -I$(LIBFT_DIR)

MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBS = -L$(MINILIBX_DIR) -lmlx -L/opt/X11/lib -lX11 -lXext

SRCS = srcs/main.c \
		srcs/atoi_positive.c \
		srcs/check_file_lines.c \
		srcs/free_and_exit.c \
		srcs/game.c \
		srcs/load_textures.c \
		srcs/parse_colors.c \
		srcs/parse_elements.c \
		srcs/parse_map.c \
		srcs/process_file.c \
		srcs/raycast.c \
		srcs/render_ray.c \
		srcs/rotations.c \
		srcs/tex_calc.c \
		srcs/validate_map.c

OBJS = $(SRCS:.c=.o)

all: $(MINILIBX) $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	@make -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx.a:
	if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX) $(LIBS) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
