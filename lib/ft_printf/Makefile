# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/08/15 18:20:30 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SOURCES		= libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c \
libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_calloc.c \
libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
libft/ft_isspace.c

PRINTF_SOURCES		= ${LIBFT_SOURCES} ft_printf.c ft_printfcom.c ft_printfcom2.c

INCLUDES			= ft_printf.h libft/libft.h

LIBFT_OBJS			= ${LIBFT_SOURCES:.c=.o}
PRINTF_OBJS			= ${PRINTF_SOURCES:.c=.o}

LIBFT_NAME			= libft.a
PRINTF_NAME			= libftprintf.a

CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all: ${LIBFT_NAME} ${PRINTF_NAME}

${LIBFT_NAME}: ${LIBFT_OBJS}
	ar rcs ${LIBFT_NAME} ${LIBFT_OBJS}

${PRINTF_NAME}: ${LIBFT_NAME} ${PRINTF_OBJS}
	ar rcs ${PRINTF_NAME} ${PRINTF_OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${LIBFT_OBJS} ${PRINTF_OBJS}

fclean: clean
	${RM} ${LIBFT_NAME} ${PRINTF_NAME}

re: fclean all

.PHONY: all clean fclean re
