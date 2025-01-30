CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g
NAME = so_long
SRC = so_long.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

# Cible principale
all: $(NAME)

# Construction de l'exécutable en respectant les dépendances
$(NAME): $(OBJ) $(LIBFT)
	@echo "Compiling libraries..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "libraries compiled successfully!"

# Compilation des bibliothèques externes
$(LIBFT):
	@make -s -C $(LIBFT_PATH) bonus

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(LIBFT_PATH) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJ)
	@make -s -C $(LIBFT_PATH) clean

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_PATH) fclean

# Rebuild complet
re: fclean all