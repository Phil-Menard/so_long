CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

# Dossier des fichiers objets
OBJ_DIR = objs

# Fichiers sources
SRC = ft_isalpha.c \
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
	ft_printf.c \
	ft_printnumber.c \
	ft_printhexa.c \
	ft_printaddress.c \
	ft_strfindchar.c \
	ft_putline.c \
	ft_putstr.c \
	ft_realloc.c \
	get_next_line.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

# Ajout des préfixes de dossiers
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
BONUS_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))

# Compilation principale
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar cr $(NAME) $(OBJ) $(BONUS_OBJ)

# Compilation des fichiers objets dans OBJ_DIR
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier OBJ_DIR si nécessaire
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et du dossier OBJ_DIR
clean:
	@rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)

# Rebuild complet
re: fclean all
