NAME	= cub3D

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -ggdb
RM	= rm -f

I_PATH	= ./includes
M_PATH	= ./minilibx-linux

INCLUDES	= -I ${I_PATH}

SRCS	=	srcs/main.c							\
			srcs/utils/str_utils_1.c			\
			srcs/utils/str_utils_2.c    		\
			srcs/checks/file_checks.c			\
			srcs/file_reader/basic_gnl.c		\
			srcs/list_manage/textures.c			\
			srcs/file_reader/element_reader.c	\
			srcs/list_manage/elems.c			\
			srcs/list_manage/check_elems.c		\
			debug/display_textures_list.c		\

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}	: ${OBJS} ${SRCS}
	${CC} ${CFLAGS} ${OBJS} ${INCLUDES} -o ${NAME}

clean:
	${RM} ./*.o
	${RM} ./*/*.o
	${RM} ./*/*/*.o
	${RM} ./*/*/*/*.o

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re
