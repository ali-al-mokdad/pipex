# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/09/11 16:05:48 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIB = lib/ft_printf/libftprintf.a

SRCS  = src/pipex_main.c src/pipex_utils.c

BONUS_SRCS = src/main_bonus.c src/bonus_utils.c src/pipex_utils.c lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all: $(NAME) 

bonus: $(BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIB)  -o $(NAME)


$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
			@make -C ./lib/ft_printf

src/%.o: src/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:	
		@make clean -C ./lib/ft_printf
		${RM} ${OBJS}
		${RM} $(BONUS_OBJS)

fclean: clean
		${RM} ${LIB}
		${RM} ${NAME}
		rm -rf checker

re: fclean all

.PHONY: all bonus clean fclean re
