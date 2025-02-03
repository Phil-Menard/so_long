CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g
NAME = so_long

# Dossiers
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_PATH = libft

# Fichiers sources
SRC = so_long.c \
	utils.c \
	map.c \
	player.c \
	init_and_close.c

# Ajout des préfixes de dossiers
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Bibliothèque libft
LIBFT = $(LIBFT_PATH)/libft.a

# Cible principale
all: $(OBJ_DIR) $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ) $(LIBFT)
	@echo "Compiling libraries..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Libraries compiled successfully!"

# Compilation des bibliothèques externes
$(LIBFT):
	@make -s -C $(LIBFT_PATH) bonus

# Compilation des fichiers objets dans OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(LIBFT_PATH) -I/usr/include -Imlx_linux -c $< -o $@

# Création du dossier OBJ_DIR si nécessaire
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et du dossier OBJ_DIR
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_PATH) clean

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_PATH) fclean

# Rebuild complet
re: fclean all
