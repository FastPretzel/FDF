NAME = fdf
NAME_B = fdf_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g -Ofast
FILES = main.c	utils.c	ft_split.c\
		get_next_line.c	get_next_line_utils.c\
		utils_2.c	parse_map.c\
		parse_points.c	ft_atoi.c\
		draw.c	hooks.c\
		rotate.c ft_strnstr.c\
		init.c	init_point.c
FILES_B = main_bonus.c	utils_bonus.c	ft_split_bonus.c\
		get_next_line_bonus.c	get_next_line_utils_bonus.c\
		parse_map_bonus.c	utils_2_bonus.c\
		parse_points_bonus.c	ft_atoi_bonus.c\
		draw_bonus.c	hooks_bonus.c\
		rotate_bonus.c ft_strnstr_bonus.c\
		init_bonus.c	init_point_bonus.c

VPATH = srcs/\
		srcs_bonus/

HEADERS = includes/fdf.h\

FILES_O = $(addprefix objs/, $(notdir $(FILES)))
FILES_O_B = $(addprefix objs/, $(notdir $(FILES_B)))
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES_O:.c=.o)
OBJS_B = $(FILES_O_B:.c=.o)
OBJDIR = objs/

NB = $(words $(FILES))
INDEX = 0

objs/%.o : %.c Makefile $(HEADERS)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@$(eval PERCENT=$(shell expr $(INDEX) '*' 100 / $(NB)))
	@$(eval PROGRESS=$(shell expr $(INDEX) '*' 30 / $(NB)))
	@printf "\r\033[38;5;87mMAKE FDF %2d%%\033[0m \033[48;5;32m%*s\033[0m %s\033[K" $(PERCENT) $(PROGRESS) "" $(notdir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/

bonus: $(OBJDIR) $(NAME_B)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
	@printf "\r\033[38;5;82mFDF DONE\033[0m\033[K\n"

$(NAME_B) : $(OBJS_B)
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_B) $(OBJS_B)
	@printf "\r\033[38;5;82mFDF BONUS DONE\033[0m\033[K\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@printf "\033[38;5;85mCLEAN\033[0m\n"

fclean : clean
	@rm -rf $(NAME) $(NAME_B)
	@printf "\033[38;5;84mFULL CLEAN\033[0m\n"

re: fclean all
