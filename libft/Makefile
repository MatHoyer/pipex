CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -MMD

AFFICHAGE_SRC =  ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c 

CARAC_SRC = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c 

CONVERT_SRC = ft_atoi.c \
	ft_itoa.c \
	ft_itoa_unsigned.c

GNL_SRC = get_next_line.c \
	get_next_line_utils.c

LST_SRC = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

MEM_SRC = ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c

PRINTF_SRC = ft_aff.c \
	ft_case.c \
	ft_convert_base_long.c \
	ft_convert_base.c \
	ft_printf.c

STR_SRC = ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c

AFFICHAGE_PATH = affichage/
CARAC_PATH = carac/
CONVERT_PATH = convert/
GNL_PATH = gnl/
LST_PATH = lst/
MEM_PATH = mem/
PRINTF_PATH = printf/
STR_PATH = str/

AFFICHAGE = $(addprefix $(AFFICHAGE_PATH), $(AFFICHAGE_SRC))
CARAC = $(addprefix $(CARAC_PATH), $(CARAC_SRC))
CONVERT = $(addprefix $(CONVERT_PATH), $(CONVERT_SRC))
GNL = $(addprefix $(GNL_PATH), $(GNL_SRC))
LST = $(addprefix $(LST_PATH), $(LST_SRC))
MEM = $(addprefix $(MEM_PATH), $(MEM_SRC))
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_SRC))
STR = $(addprefix $(STR_PATH), $(STR_SRC))

SRC = $(AFFICHAGE) \
	$(CARAC) \
	$(CONVERT) \
	$(GNL) \
	$(LST) \
	$(MEM) \
	$(PRINTF) \
	$(STR)

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

NAME = libft.a

all : $(NAME)

$(NAME) :
	@echo "Compilation de libft en cours..."
	@make -s compile
	@echo "Terminé!"

compile: $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "Suppression des objets et des dependances"
	@rm -f $(OBJ) $(DEP)
	@echo "Terminé!"

fclean : clean
	@echo "Suppression de libft.a"
	@rm -f $(NAME)
	@echo "Terminé!"

-include $(DEP)

re : fclean all

.PHONY : all compile clean fclean re
