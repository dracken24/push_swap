# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 23:19:21 by nadesjar          #+#    #+#              #
#    Updated: 2022/04/29 23:19:21 by nadesjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED	= $(shell tput -Txterm setaf 1)
LIGHT_GREEN	= $(shell tput -Txterm setaf 2)
LIGHT_BROWN	= $(shell tput -Txterm setaf 3)
CYAN		= $(shell tput -Txterm setaf 4)
LILAS		= $(shell tput -Txterm setaf 5)
LIGHT_CYAN	= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= "\033[0m"

PATH_OBJS 	= ./objs/
PATH_SRC	= ./src/
PATH_RUN	= ./src/run/
PATH_UTILS  = ./src/utils/

FILES 		= $(PATH_SRC)push_swap.c $(PATH_UTILS)check_entry.c $(PATH_UTILS)using_malloc.c \
			$(PATH_UTILS)moves_1.c $(PATH_UTILS)moves_2.c $(PATH_UTILS)utils.c $(PATH_UTILS)split_this.c \
			$(PATH_RUN)big_run.c \
			$(PATH_RUN)run02.c $(PATH_RUN)med_run_1.c $(PATH_UTILS)utils_2.c \
			$(PATH_RUN)med_run_2.c $(PATH_RUN)big_run_2.c \

OBJS 		= $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
AR 			= ar -rcs

PRINTF		= make_lib
PRINTF_A	= ft_printf/libftprintf.a

NAME 		= push_swap.a

REMOVE		= ./ft_printf/*.o ./ft_printf/libft/atoitoa/*.o ./ft_printf/libft/is/*.o \
			./ft_printf/libft/lst/*.o ./ft_printf/libft/math/*.o \
			./ft_printf/libft/mem_alloc/*.o ./ft_printf/libft/mem_move/*.o \
			./ft_printf/libft/str/*.o ./ft_printf/*.a ./ft_printf/libft/*.a \
			./src/*.o push_swap gcc \

all: $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	@echo $(LILAS)"COMPILE MOI CE PUSH_SWAP LA..."$(RESET)
	cp $(PRINTF_A) $(NAME)
	gcc $(CFLAGS) $(OBJS) $(PRINTF_A) -Og -o push_swap
	@echo $(LILAS)"ENFIN, LA LUMIERE AU BOUT DU TUNEL !!!"$(RESET)

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)run
	$(CC) $(CFLAGS) -c $< -o $@

make_lib:
	$(MAKE) -C ./ft_printf

push:
	@(git add .)
	@(git commit -m "nadesjar42")
	@(git push)

clean:
	@rm -f $(OBJ) $(REMOVE)
	@rm -fr ./objs
	@echo $(LIGHT_GREEN)"BYE BYE"$(RESET)

fclean: clean
	@rm -f $(NAME) $(LIBFT_A)
	
re:	fclean all

.PHONY: all make_lib push clean fclean re