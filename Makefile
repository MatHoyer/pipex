CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -MMD -g3

SRC_PATH = sources/

OBJS_PATH = obj/

SRC = main.c \
	do.c \
	free_all.c \
	get_cmd.c \
	get_path.c \
	msg_error.c \
	pipex.c \

SRC_BONUS = main_bonus.c \
	do.c \
	free_all.c \
	get_cmd.c \
	get_path.c \
	msg_error.c \
	pipex.c \

OBJS = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
PREFC = $(addprefix $(SRC_PATH),$(SRC))
PREFO = $(addprefix $(OBJS_PATH),$(OBJS))
PREFD = $(addprefix $(OBJS_PATH),$(DEP))


OBJSB = $(SRC_BONUS:.c=.o)
DEPB = $(SRC_BONUS:.c=.d)
PREFCB = $(addprefix $(SRC_PATH),$(SRC_BONUS))
PREFOB = $(addprefix $(OBJS_PATH),$(OBJSB))
PREFDB = $(addprefix $(OBJS_PATH),$(DEPB))

OBJ_DIR = obj

NAME = pipex
BONUS = pipex_bonus

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(PREFO)
	@make -s -C libft all
	@echo "Compilation de pipex en cours..."
	@$(CC) $(PREFO) ./libft/libft.a -o $(NAME)
	@echo "Terminé!"

$(BONUS) : $(PREFOB)
	@make -s -C libft all
	@echo "Compilation de pipex_bonus en cours..."
	@$(CC) $(PREFOB) ./libft/libft.a -o $(BONUS)
	@echo "Terminé!"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean

fclean :
	@rm -f $(NAME) $(BONUS)
	@rm -rf $(OBJ_DIR)
	@echo "Suppression de ./pipex et ./pipex_bonus"
	@echo "Terminé!"
	@make -s -C libft fclean

re : fclean all

-include $(PREFD)
-include $(PREFDB)

.PHONY : all clean fclean re