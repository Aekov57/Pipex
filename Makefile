# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:29:09 by misimon           #+#    #+#              #
#    Updated: 2022/06/23 18:44:28 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# ============================================================================ #
# ==============================|	FILES	|================================= #
# ============================================================================ #

MAIN_SRC = main define_var shell_cmd_path exec_cmd\

ALL_SRC += $(addsuffix .c, $(MAIN_SRC))

LIBFT_SRC = ft_split ft_strjoin ft_strlen ft_strncmp\

ALL_SRC += $(addprefix Libft/, $(addsuffix .c, $(LIBFT_SRC)))

#ALL_SRC += $(addprefix CheckFunction/, $(addsuffix .c, $(CHECK_SRC)))#

OBJS = $(ALL_SRC)

# ============================================================================ #
# ==============================|	 CMD	|================================= #
# ============================================================================ #

all : $(NAME)

$(NAME) : $(OBJS)
	@clear
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


norm :
	@clear
	@norminette

clean :
	@rm -f ./pipex

fclean : clean
	@rm -f ./pipex

re : fclean all