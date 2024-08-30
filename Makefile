NAME = client
NAME2 = server
BONUS_NAME = client_bonus
BONUS_NAME2 = server_bonus

LIBFT = libft.a
PRINTF = libftprintf.a
CLIENT_SRC =	client.c
SERVER_SRC =	server.c
CLIENT_BONUS_SRC = client_bonus.c 
SERVER_BONUS_SRC = server_bonus.c


CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_BONUS_OBJ = ${CLIENT_BONUS_SRC:.c=.o}
SERVER_BONUS_OBJ = ${SERVER_BONUS_SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I Include
RM = rm -rf

all:	$(NAME) $(NAME2)

$(NAME) : $(CLIENT_OBJ)
		@make -C Libft
		@make -C Ft_Printf
		$(CC) $(CFLAGS) $(CLIENT_OBJ) $(INCLUDE) Ft_Printf/$(PRINTF) Libft/$(LIBFT) -o $(NAME)

$(NAME2) : $(SERVER_OBJ)
		@make -C Ft_Printf
		$(CC) $(CFLAGS) $(SERVER_OBJ) $(INCLUDE) Ft_Printf/$(PRINTF) -o $(NAME2)

bonus : $(BONUS_NAME) $(BONUS_NAME2)

$(BONUS_NAME) : $(CLIENT_BONUS_OBJ)
		@make -C Libft
		@make -C Ft_Printf
		$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ)  $(INCLUDE)  Ft_Printf/$(PRINTF) Libft/$(LIBFT) -o $(BONUS_NAME)

$(BONUS_NAME2) : $(SERVER_BONUS_OBJ)
		@make -C Ft_Printf
		$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ)  $(INCLUDE)  Ft_Printf/$(PRINTF) -o $(BONUS_NAME2)

clean :
		@make clean -C Libft
		@make clean -C Ft_Printf
		${RM} ${CLIENT_OBJ}
		${RM} ${SERVER_OBJ}
		${RM} ${CLIENT_BONUS_OBJ}
		${RM} ${SERVER_BONUS_OBJ}

fclean : clean
		@make fclean -C Libft
		@make fclean -C Ft_Printf
		${RM} $(NAME)
		${RM} $(NAME2)
		${RM} $(BONUS_NAME)
		${RM} $(BONUS_NAME2)
		${RM} $(LIBFT)
		${RM} $(PRINTF)

re : fclean all

.PHONY:	all bonus clean fclean re