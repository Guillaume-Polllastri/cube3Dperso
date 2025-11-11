# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ep <ep@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 00:19:30 by erpascua          #+#    #+#              #
#    Updated: 2025/09/22 21:16:03 by ep               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
AR			=	ar rcs
RM			=	rm -f

SRC			=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				er_args_join.c \
				er_atol.c \
				er_splits_spaces.c \
				er_is_space.c \
				er_free_tab.c \
				ft_strcmp.c \
				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \
				ft_fprintf.c \
				ft_printf_utils.c \
				ft_putstr.c \
				ft_sqrt.c \
				ft_strcpy.c \
				get_next_line.c \
				get_next_line_utils.c \
				printf_char.c \
				printf_hex_low.c \
				printf_hex_upp.c \
				printf_int.c \
				printf_percent.c \
				printf_ptr.c \
				printf_str.c \
				printf_unsigned.c \
				print_string_array.c
			
SRC_BONUS = 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
			
OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

################################################################################
#																			   #
#									  RULES									   #
#																			   #
################################################################################


all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "✅  $@ built"

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)
	@echo "✅  Libft: Objects files deleted"

bonus: $(OBJ_BONUS) $(NAME)
	@$(AR) $(NAME) $(OBJ_BONUS)
	@echo "✅  Libft: Binaries deleted"

re: fclean all

.PHONY: all clean fclean re
