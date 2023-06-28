CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -MMD -g3

SRC_PATH = sources/

OBJS_PATH = obj/

SRC = free_all.c \
	get_path.c \
	main.c \
	msg_error.c \
	pipex.c \

OBJS = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

PREFC = $(addprefix $(SRC_PATH),$(SRC))

PREFO = $(addprefix $(OBJS_PATH),$(OBJS))

PREFD = $(addprefix $(OBJS_PATH),$(DEP))

OBJ_DIR = obj

NAME = pipex

all : $(NAME)

$(NAME) : $(PREFO)
	@make -s -C libft all
	@echo "Compilation de pipex en cours..."
	@$(CC) $(PREFO) ./libft/libft.a -o $(NAME)
	@echo "Terminé!"

bonus : all

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make -s -C libft fclean

re : fclean all

-include $(PREFD)

.PHONY : all clean fclean re