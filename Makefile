CFLAGS  = -Wall -Wextra -Werror

CLIENT = client 

SERVER = server

LIBFT = libft/libft.a

INC = -I libft/includes

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) client.c
	@gcc $(CFLAGS) $(INC) -o $(CLIENT) client.c $(LIBFT)

$(SERVER): $(LIBFT) server.c
	@gcc $(CFLAGS) $(INC) -o $(SERVER) server.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo 🔥 🔥 Making Executables ✅ ✅

clean:
	@make -C libft clean
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER)
	@echo  🔥 🔥 Deleting executables files 🗑️ 🗑️

re: fclean all

bonus: fclean $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) client_bonus.c
	@gcc $(CFLAGS) $(INC) -o $(CLIENT) client_bonus.c $(LIBFT)

$(SERVER): $(LIBFT) server_bonus.c
	@gcc $(CFLAGS) $(INC) -o $(SERVER) server_bonus.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo 🔥 🔥 Making Executables ✅ ✅


.PHONY: all clean fclean re bonus