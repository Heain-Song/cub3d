NAME	= cub3D

CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror -I ./include -I minilibx -ggdb
MLXFLAGS	= -Lminilibx -lm -lmlx -lXext -lX11 -lz
RM			= rm -f

I_PATH		= ./includes
M_PATH		= ./minilibx

INCLUDES	= -I ${I_PATH}

SRCS	=	srcs/main.c								\
			srcs/utils/str_utils_1.c				\
			srcs/utils/str_utils_2.c    			\
			srcs/checks/file_checks.c				\
			srcs/file_reader/basic_gnl.c			\
			srcs/list_manage/textures.c				\
			srcs/file_reader/element_reader.c		\
			srcs/list_manage/elems.c				\
			srcs/list_manage/check_elems.c			\
			srcs/file_reader/element_chose.c		\
			srcs/utils/ft_atoi.c					\
			srcs/utils/2d_add.c						\
			srcs/file_reader/map_reader.c			\
			srcs/file_reader/map_parser.c			\
			srcs/errors_print/error_input_file.c	\
			srcs/file_reader/map_parser_utils.c		\
			srcs/mlx_manage/mlx_init.c				\
			srcs/mlx_manage/mlx_cleaner.c			\
			srcs/file_reader/textures.c				\
			srcs/file_reader/type_in_map.c			\
			srcs/file_reader/color_parsing.c		\
			srcs/visuals/main_loop.c				\
			srcs/visuals/draw.c						\
			srcs/visuals/maths.c					\
			srcs/raycasting/start.c					\
			debug/display_textures_list.c			\
			debug/print_map.c						\
			debug/loop.c							\
			debug/print_elems_map.c					\
			srcs/raycasting/test_untextured.c		\

OBJS	=	${SRCS:.c=.o}

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}	:	${OBJS} ${SRCS}
			make -C ${M_PATH}
			${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} ${INCLUDES} -o ${NAME}

clean:
			${RM} ./*.o
			${RM} ./*/*.o
			${RM} ./*/*/*.o
			${RM} ./*/*/*/*.o

fclean:		clean
			make clean -C ${M_PATH}
			${RM} ${NAME}

re:			clean all

.PHONY:		all clean fclean re
