# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 13:24:42 by nsiefert          #+#    #+#              #
#    Updated: 2024/03/05 11:01:54 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT					= client
SERVER					= server
CLIENT_BONUS			= client_bonus
SERVER_BONUS			= server_bonus

CC						= cc
FLAGS					= -Werror -Wall -Wextra -g3

INC_DIR					= includes/
SRC_DIR_MAND			= srcs/mandatory/
SRC_DIR_BONUS			= srcs/bonus/
OBJ_DIR_MAND			= objs/mandatory/
OBJ_DIR_BONUS			= objs/bonus/

LIBFT_PATH				= libft/
LIBFT_EX				= libft.a

SRCS_CLIENT_MANDATORY	= client.c utils.c
SRCS_SERVER_MANDATORY	= server.c utils.c

SRCS_CLIENT_BONUS		= client_bonus.c utils_bonus.c
SRCS_SERVER_BONUS		= server_bonus.c utils_bonus.c

OBJ_CLIENT				= $(addprefix $(OBJ_DIR_MAND), $(SRCS_CLIENT_MANDATORY:.c=.o))
OBJ_SERVER				= $(addprefix $(OBJ_DIR_MAND), $(SRCS_SERVER_MANDATORY:.c=.o))

OBJ_CLIENT_BONUS		= $(addprefix $(OBJ_DIR_BONUS), $(SRCS_CLIENT_BONUS:.c=.o))
OBJ_SERVER_BONUS		= $(addprefix $(OBJ_DIR_BONUS), $(SRCS_SERVER_BONUS:.c=.o))

all : lib obj_man $(CLIENT) $(SERVER)

bonus : lib obj_bon $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(OBJ_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJ_CLIENT) -I $(INC_DIR) -I $(LIBFT_PATH)$(INC_DIR) -L$(LIBFT_PATH) -lft

$(SERVER) : $(OBJ_SERVER)
	$(CC) $(FLAGS) -o $(SERVER) $(OBJ_SERVER) -I $(LIBFT_PATH)$(INC_DIR) -L$(LIBFT_PATH) -lft

$(CLIENT_BONUS) : $(OBJ_CLIENT_BONUS)
	$(CC) $(FLAGS) -o $(CLIENT_BONUS) $(OBJ_CLIENT_BONUS) -I $(INC_DIR) -I $(LIBFT_PATH)$(INC_DIR) -L$(LIBFT_PATH) -lft

$(SERVER_BONUS) : $(OBJ_SERVER_BONUS)
	$(CC) $(FLAGS) -o $(SERVER_BONUS) $(OBJ_SERVER_BONUS) -I $(INC_DIR) -I $(LIBFT_PATH)$(INC_DIR) -L$(LIBFT_PATH) -lft

$(OBJ_DIR_MAND)%.o : $(SRC_DIR_MAND)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_PATH)$(INC_DIR)

$(OBJ_DIR_BONUS)%.o : $(SRC_DIR_BONUS)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_PATH)$(INC_DIR)

obj_bon :
	@mkdir -p objs/bonus/

obj_man :
	@mkdir -p objs/mandatory/

lib :
	@make -sC $(LIBFT_PATH)

clean :
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_DIR_MAND) $(OBJ_DIR_BONUS)

fclean : clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make fclean -sC $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re